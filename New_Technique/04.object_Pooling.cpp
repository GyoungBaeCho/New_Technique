#include "stdafx.h"

//#include <iostream>
//#include <list>
//#include "Function_Tool.h"

class CObject{
	float matrix[16];

};

template<typename T>
class CObjectPool{
private:
	list<T*> m_lpObjectPool;

public:
	//���� pool�� �̹� �����Ͱ� �ִٸ� ������ ����, ���ٸ� ���� �Ҵ��ؼ� ��ȯ�Ѵ�.
	T* NewObject(){
		if(m_lpObjectPool.size() != 0){
			CObject* pReturn = m_lpObjectPool.front();
			m_lpObjectPool.pop_front();
			return pReturn;
		}
		else{
			return new T;
		}
	}

	//��ü�� ������ ���� ������, �������� ���� ���⿡ �־��.
	void RemoveObject(T* pObject){
		m_lpObjectPool.push_back(pObject);
		pObject = nullptr;
	}
};

int main(){
	CObject* pObject;


	cout << "Non-Pooling" << endl;
	BeginTimer();
		for(int i=0 ; i<100000 ; i++){
			pObject = new CObject;
			delete pObject;
		}
	EndTimer();
	cout << endl;

	CObjectPool<CObject> objectPool;;
	cout << "Pooling" << endl;
	BeginTimer();
		for(int i=0 ; i<100000 ; i++){
			pObject = objectPool.NewObject();
			objectPool.RemoveObject(pObject);
		}
	EndTimer();
	cout << endl;

}

/*
//�����͸� �������� �����ϰ� �����ϴ� ���� �ƴ϶� Pooling�� ����ϴ°��� �󸶳� ���� ��� ������ �Ǵ����� �׽�Ʈ.
-------------Result

,400,000

Debug	: 0.0037081
result	: 0.0006744

*/