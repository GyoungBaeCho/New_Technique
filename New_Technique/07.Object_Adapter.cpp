#include "stdafx.h"

//Aggregation : �ڽ��� �����ϰ� �ִ� �����̳ʰ� �Ҹ��ص�, �ڽ��� ��� �ִ�.
//Composition : �ڽ��� �����ϰ� �ִ� �����̳ʰ� �Ҹ��ϸ�, �ڽŵ� �Ҹ� �ȴ�.

//��� ��ü�� �ٷ� ��ü�� Super Class �̴�.
class CObject{
public:
	CObject(){}
	virtual ~CObject(){}
	
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
	virtual ~CUi(){}

	virtual void UpdateUi() = 0;
	virtual void RenderUi() = 0;
};

class CButtonUi : public CUi{
public:
	CButtonUi(){}
	~CButtonUi(){}

	virtual void UpdateUi(){ cout << "Ui - Button - Update" << endl; }
	virtual void RenderUi(){ cout << "Ui - Button - Render" << endl; }
};

//CObject�� ������ ������ CUi ��ü�� CObject�� ����Ŭ������ ���۽�ų �� �ִ� Adapter
//-------------------------------------------------
class CObjectAdapter : public CObject{
	//Composition ��ü.
	CUi* m_pUi;

public:
	CObjectAdapter() : m_pUi(nullptr){}
	CObjectAdapter(CUi* pUi) : m_pUi(pUi){}
	~CObjectAdapter(){ if(m_pUi) delete m_pUi; }

	virtual void Update(){ if(m_pUi) m_pUi->UpdateUi(); }
	virtual void Render(){ if(m_pUi) m_pUi->RenderUi(); }

};

int main(){
	vector<CObject*> vpObject;
	CObject* pNewObject = nullptr;

	vpObject.push_back(new CNpcObject);
	vpObject.push_back(new CObjectAdapter(new CButtonUi));
	
	for(CObject *pObject : vpObject){
		pObject->Update();
		pObject->Render();
		cout << endl;
	}
}