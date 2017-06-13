#include "stdafx.h"

//��� ��ü�� �ٷ� ��ü�� Super Class �̴�.
class CObject{
public:
	CObject(){}
	~CObject(){}
	
	virtual void Update() = 0;

	virtual void Render() = 0;
};

class CNpcObject : public CObject{
public:
	CNpcObject(){}
	~CNpcObject(){}

	virtual void Update(){ cout << "Object - NPC - Update" << endl; }
	virtual void Render(){ cout << "Object - NPC - Render" << endl; }
};


//CObject ��ü�ʹ� ������ ������ CUi ��ü
//-------------------------------------------------
class CUi{
public:
	CUi(){}
	~CUi(){}

	void UpdateUi(){ cout << "Ui - Button - Update" << endl; }
	void RenderUi(){ cout << "Ui - Button - Render" << endl; }
};

//CObject�� ������ ������ CButtonUi ��ü�� CObject�� ����Ŭ������ ���۽����ִ� Adapter
//-------------------------------------------------
class CObjectAdapter : public CObject, CUi{
public:
	CObjectAdapter(){}
	~CObjectAdapter(){}

	virtual void Update(){ CUi::UpdateUi(); }
	virtual void Render(){ CUi::RenderUi(); }
};

//-------------------------------------------------
int main(){
	vector<CObject*> vpObject;
	CObject* pNewObject = nullptr;

	vpObject.push_back(new CNpcObject);
	vpObject.push_back(new CObjectAdapter);
	
	for(CObject *pOBject : vpObject){
		pOBject->Update();
		pOBject->Render();
		cout << endl;
	}

	/*
	CObjectAdapter class�� Base class�� CObject Ŭ�����̹Ƿ�, 
	�� �̿��� ���� ����� Ŭ�����δ� �������� �̷� �� ����.
	CUi* pUi = new CObjectAdapter;
*/
}