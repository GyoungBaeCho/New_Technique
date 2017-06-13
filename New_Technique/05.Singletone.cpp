#include "stdafx.h"

/*
	Singletone ��ü�� ������,

	�ν��Ͻ��� �ϳ��� �����ǵ����Ͽ� ������ �̿��� �����ϰ�,

	�޸� �Һ��� ���� ��ü������, ��뷮�� ���� ���, '������ ����'�� ���Ͽ� �������߿� �ٷ� �����Ͽ�

	�޸𸮸� �������� �ʴ´ٴ� ���� �ִ�.


	[��������]���� ���� �����Ͻÿ� �ٷ� �޸𸮰� �Ҵ�ǹǷ�, ���� ���ϴٴ� ���ε�..

	C++������ Java�� �޸� �����͸� �����ϴ� �̷� ������ ���°� �ƴѰ�???
*/ 

class CSingletone{
private:
	static CSingletone* m_pInstance;

private:
	CSingletone(){
		cout << "�̱��� ����!" << endl; 
	}
	~CSingletone(){}

public:
	static void CreateSingletone(){ if(!m_pInstance) m_pInstance = new CSingletone; }
	static CSingletone* GetInstance(){ return m_pInstance; }

	void Render(){ 
		cout << "���� Singletone!!" << endl; 
	}
};

_declspec(selectany) CSingletone* CSingletone::m_pInstance = nullptr;

int main(){
	CSingletone::CreateSingletone();
	CSingletone::GetInstance()->Render();

	cout << CSingletone::GetInstance() << endl;
}

//#pragma pack(push, 1)
//struct pack {
//    char array[9];
//    int    len;
//};
//#pragma pack(pop)
//
//class CSingletone{
//private:
//	static CSingletone m_Instance;
//
//private:
//	CSingletone(){}
//	~CSingletone(){}
//
//public:
//	static CSingletone* GetInstance(){
//		return &m_Instance; 
//	}
//
//	void Render(){ 
//		cout << "���� Singletone!!" << endl; 
//	}
//};
//_declspec(selectany) CSingletone CSingletone::m_Instance;
//
//int main(){
//	CSingletone::GetInstance()->Render();
//
//	cout << endl << CSingletone::GetInstance() << endl;
//}
//
//
//
#define SINGLETONE(type)								\
		public:											\
		static type* GetInstance(){						\
			static type instance;						\
			return &instance;							\
		}

class CObject{
private:

private:

public:
	SINGLETONE(CObject);

	void Render(){
		cout << "���� �̱����̴�" << endl;
	}
};

int main(){
	CObject::GetInstance()->Render();
}
//	atexit();