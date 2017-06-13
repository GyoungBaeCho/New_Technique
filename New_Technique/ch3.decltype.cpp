#include "stdafx.h"

#include <iostream>
using namespace std;

#include <typeinfo>

/*
	decltype - ���� ������ �ڷ����� ����Ѵ�.
*/

//�������� ������ ���� �ڵ�� ������ �Ұ����ߴ�.
//���ø����� ���� �ΰ��� �ٸ� �ڷ����� �Լ� ������� ������, �Ǽ��ĸ�
//���� �˾Ƽ� ��ȯ�ϴ� ������ �Ұ��� �ߴ�.
template<typename T1, typename T2>
decltype(x+y) FunctionAdd1(T1 x, T2 y){}

//������ ���� ������ ���� ���� �����ϴ�.
template<typename T1, typename T2>
auto FunctionAdd2(T1 x, T2 y) -> decltype(x + y)
{
	return x + y;
}

int main(){
	int num;

	//���޵� ������ �ڷ������� ���ο� ������ �����Ѵ�.
	decltype(num) a;
	a = 100;
	cout << a << endl;
		
	//���� �Լ��� ������ �Ұ��� �ϴ�.
	//decltype(x + y) �κп��� x, y�� ��� �������� �������� ���Ѵ�.
	//FunctionAdd2(10, 20);

	//������ ��ȯ�ϴ� �ڷ����� �ٸ��ٴ� ���� �� �� �ִ�.
	cout << typeid(FunctionAdd2(10, 10)).name() << endl;
	cout << typeid(FunctionAdd2(10, (float)10)).name() << endl;
	cout << typeid(FunctionAdd2(10, 10.0)).name() << endl;

}

