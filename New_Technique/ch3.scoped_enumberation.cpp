#include "stdafx.h"

#include <iostream>
using namespace std;

///<summary> ��ȣ��ȣ </summary>
enum ANIMATION1 : int {
	WALK,	RUN,	JUMP,	DEAD,
};

///<summary> ��ȣ��ȣ </summary>
enum class ANIMATION2 : int {
	WALK,	RUN,	JUMP,	DEAD,
};

int main(){
	cout << ANIMATION1::WALK << endl;

	//enum class�� ����ȯ�� ���� �ʴ´�. ���� ���� �ڵ�� ������ �Ұ��� �ϴ�.
	cout << ANIMATION2::WALK << endl;

	ANIMATION2 ani;


	switch(ani){
	//�Ϲ� enum�� ANIAMTION1�� ȣ���� ���� �ʴ´�.
	case ANIMATION1::WALK:
		break;
	case ANIMATION2::RUN:
		break;
	case ANIMATION2::JUMP:
		break;
	}

}