#include "stdafx.h"

/*
��Ģ 1 : �ٲ� �� �ִ� �κ��� ã�Ƴ��� �ٲ��� �ʴ� �κа� �и����Ѿ� ��.

��Ģ : Ư�� ������ �������� ���α׷��� ���� ����

new�� ���� ��ü�̴�.
	���� Ŭ������ �ν��Ͻ��� ����� ���̴�.
	new�� ����ϴ� ���� �ᱹ Ư�� ������ ����ϴ� ���̹Ƿ�, ��Ģ�� ����ȴ�.
*/


/*
	������ ���丮 ����			: ��ü ������ ó���ϴ� Ŭ����

	���丮 �޼ҵ� ����	: ��ü�� �����ϱ� ���� �������̽� class�� � ��ü�� �������� ���� ����
						  ���� Ŭ�������� �����ϵ��� ���� ����

	���� ���丮 ����	: ���丮 class�� �ν��Ͻ��� ������ �ʿ� ���� ����� �� �ֵ��� �� ���丮
						  �ٸ� ���� Ŭ������ ���� �ൿ�� �����ų �� ����?? ����
*/

#define SIMPLE_FACTORY

#define METHOD_FACTORY


enum class UnitType{
	//Terran
	MARINE,
	SCV,
	MEDIC,

	//Protoss
	PROBE,
	CARRIER,
	DARK_TEMPLAR,
};

class CUnit{
public:
	virtual void Render() = 0;
};

class CMarine : public CUnit{
public:
	virtual void Render(){
		cout << "Marine" << endl;
	};
};

class CScv : public CUnit{
public:
	virtual void Render(){
		cout << "Scv" << endl;
	};
};

class CMedic : public CUnit{
public:
	virtual void Render(){
		cout << "Medic" << endl;
	};
};


class CProbe : public CUnit{
public:
	virtual void Render(){
		cout << "Probe" << endl;
	};
};

class CCarrier : public CUnit{
public:
	virtual void Render(){
		cout << "Carrier" << endl;
	};
};

class CDarkTemplar : public CUnit{
public:
	virtual void Render(){
		cout << "DarkTemplar" << endl;
	};
};


class CUnitFactory{
	vector<CUnit*> m_vpUnit;
public:
	virtual CUnit* CreateObject(UnitType objType) = 0;
	void AddObject(UnitType objType){
		CUnit* pUnit = nullptr;
		pUnit = CreateObject(objType);

		pUnit->Render();
		m_vpUnit.push_back(pUnit);
	}
};

class CTerranFactory : public CUnitFactory{
public:
	virtual CUnit* CreateObject(UnitType objType){
		switch(objType){
		case  UnitType::MARINE:
			return new CMarine;
		case  UnitType::SCV:
			return new CScv;
		case  UnitType::MEDIC:
			return new CMedic;
		default:
			cout << "�߸��� ������ �Է�" << endl;
			exit(-1);
		}
	}
};

class CProtossFactory : public CUnitFactory{
public:
	virtual CUnit* CreateObject(UnitType objType){
		switch(objType){
		case  UnitType::PROBE:
			return new CProbe;
		case  UnitType::CARRIER:
			return new CCarrier;
		case  UnitType::DARK_TEMPLAR:
			return new CDarkTemplar;
			default:
			cout << "�߸��� ������ �Է�" << endl;
			exit(-1);
		}
	}
};

int main(){
	CUnitFactory *pTerranFactory = new CTerranFactory;
	CUnitFactory *pProtossFactory = new CProtossFactory;

	pTerranFactory->AddObject(UnitType::MARINE);
	pTerranFactory->AddObject(UnitType::MARINE);
	pTerranFactory->AddObject(UnitType::MARINE);
	pTerranFactory->AddObject(UnitType::MEDIC);

	pProtossFactory->AddObject(UnitType::PROBE);
	pProtossFactory->AddObject(UnitType::DARK_TEMPLAR);
	pProtossFactory->AddObject(UnitType::DARK_TEMPLAR);
}