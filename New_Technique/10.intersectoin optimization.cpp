#include "stdafx.h"
#include <iostream>
using namespace std;
#include "Function_Tool.h"

#define LOOP_NUM		1000000

inline void AAA1(const D3DXVECTOR3& vec1){}
inline void AAA2(const D3DXVECTOR3& vec1, const D3DXVECTOR3& vec2){}
inline void AAA3(const D3DXVECTOR3& vec1, const D3DXVECTOR3& vec2, const D3DXVECTOR3& vec3){}

inline bool IntersectTri(const D3DXVECTOR3& vPos1, const D3DXVECTOR3& vPos2, const D3DXVECTOR3& vPos3, const D3DXVECTOR3& vRayPos, const D3DXVECTOR3& vRayVelocity){
	D3DXVECTOR3 vIntersection;
	D3DXVECTOR3 vPlaneNormal;
	D3DXVec3Cross(&vPlaneNormal, &(vPos2 - vPos1), &(vPos3 - vPos1));

	D3DXVECTOR3 vSideNormal1;
	D3DXVec3Cross(&vSideNormal1, &vPlaneNormal, &(vPos1 - vPos2));
	D3DXVECTOR3 vSideNormal2;
	D3DXVec3Cross(&vSideNormal2, &vPlaneNormal, &(vPos2 - vPos3));
	D3DXVECTOR3 vSideNormal3;
	D3DXVec3Cross(&vSideNormal3, &vPlaneNormal, &(vPos3 - vPos1));

	float fInnerDistance,fOuterDistance;

	//����� ��ֺ��Ϳ� Shift������ ���̰��� �����ΰ��� Ȯ���մϴ�(�а��̶�� �浹�� ���ɼ� 0 %)
	if(D3DXVec3Dot(&vPlaneNormal,&vRayVelocity) > 0) return false;	//������ ������ �浹ó��

	fOuterDistance = D3DXVec3Dot(&vPlaneNormal,&(vRayPos - vPos1));
	if(fOuterDistance < 0)	return false;	// ��� ���� �̹� ���� �հ� ���� ����

	fInnerDistance = D3DXVec3Dot(&vPlaneNormal,&(vRayPos + vRayVelocity - vPos1));
	if(fInnerDistance > 0)	return false;	// ���������� �������� ���� ���� �հ� �������� ����.

	fInnerDistance *= -1;
	vIntersection = vRayPos + vRayVelocity * (fOuterDistance / (fOuterDistance + fInnerDistance));

	//vIntersection ������ �簢�� �ȿ� �ִ����� �˻��մϴ�.
	if(0 < D3DXVec3Dot(&(vIntersection - vPos1), &vSideNormal1)) return false;
	if(0 < D3DXVec3Dot(&(vIntersection - vPos2), &vSideNormal2)) return false;
	if(0 < D3DXVec3Dot(&(vIntersection - vPos3), &vSideNormal3)) return false;

	return true;
}

int main(){
	CStopWatch watch;

	vector<D3DXVECTOR3> vPoint;
	vPoint.push_back(D3DXVECTOR3(-10, +00, -10));
	vPoint.push_back(D3DXVECTOR3(+00, +00, +10));
	vPoint.push_back(D3DXVECTOR3(+10, +00, -10));
	float pu, pv, dist;


	watch.BeginTimer();
	for(int i=0 ; i<LOOP_NUM ; ++i){
		AAA1(D3DXVECTOR3(0, 0, 0));
	}
	watch.EndTimer();

	watch.BeginTimer();
	for(int i=0 ; i<LOOP_NUM ; ++i){
		AAA2(D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(0, 0, 0));
	}
	watch.EndTimer();

	watch.BeginTimer();
	for(int i=0 ; i<LOOP_NUM ; ++i){
		AAA3(D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(0, 0, 0));
	}
	watch.EndTimer();





	watch.BeginTimer();
	for(int i=0 ; i<LOOP_NUM ; ++i){
		IntersectTri(vPoint[0], vPoint[1], vPoint[2], D3DXVECTOR3(0, 5, 0), D3DXVECTOR3(0, -5, 0)) ;
	}
	watch.EndTimer();


	watch.BeginTimer();
	for(int i=0 ; i<LOOP_NUM ; ++i){
		D3DXIntersectTri(&vPoint[0], &vPoint[1], &vPoint[2], &(D3DXVECTOR3(0, 10, 0)), &(D3DXVECTOR3(0, -1, 0)), &pu, &pv, &dist) ;
	}
	watch.EndTimer();

	cout << pu << " " << pv << " " << dist << endl;

}