#include "stdafx.h"

class AAA{
private:
	int* m_pData;

public:
	AAA(){
		cout << this << " : ������" << endl;
		m_pData = new int(0);
	}
	AAA(int num){
		cout << this << " : ������" << endl;
		m_pData = new int(num);
	}
	AAA(AAA& a) : m_pData(a.m_pData){
		cout << this << " : ���������" << endl;
		a.m_pData = nullptr;
	}
	AAA(AAA&& a){
		cout << this << " : �̵�������" << endl;
		*this = move(a);

		a.m_pData = nullptr;
	//	m_pData = a.m_pData;
	//	a.m_pData = nullptr;
	}
	~AAA(){
		cout << this << " : �Ҹ���" << endl;
		if(m_pData) delete m_pData;
	}

	AAA &operator=(const AAA &copy) = default;

	int* GetData(){ return m_pData; }
};

int main(){
	vector<AAA> v1;
//	v1.emplace_back(AAA(100));
	v1.push_back(AAA(100));
	cout << *v1[0].GetData() << endl;

//���� �ڵ忡�� ������ �߻��ϴ� ����
/*
	vector Container�� �ڷ����� AAA�� �����Ͱ� �ƴ� ��ü �� ��ü��.
*/

	cout << endl;

	vector<AAA*> v2;
	v2.push_back(new AAA(100));
	cout << *(v2[0]->GetData()) << endl;
}