#include "stdafx.h"

#include <iostream>
using namespace std;

/*
	C+ 11 ���� ������ �ð��� �򰡵� �� �ִ� ǥ������ ��Ÿ���� Ű����
	Const Expression : ��� ǥ���� -> constexpr
*/

//�Ʒ��� �ΰ��� ������ ǥ�����ε� �ϴ�.
const int cnst_int = 100;
constexpr int num_of_index = 100;

//Const Expression : ��� ǥ����
constexpr int DynamicIndex(int num){
	return num;
}

//int ������ ��ȯ�ϴ� ��ȯ�ϴ� ���� �ƴ϶� const int�� ��ȯ �Կ���
//���� �Լ��� return ���� �޴� �迭�� �Ұ����ϴ�.
const int ReturnIndex(int num){
	return num;
}


int main(){
	int arr1[cnst_int];

	int arr2[num_of_index];

	//������ ���� ���´� �Ұ�
	int num = 10;
	int arr3[DynamicIndex(num)];

	//������ ���� ��� ǥ�� ��ȯ �Լ��� ���ڿ��� �ݵ�� ����� ���� �Ѵ�.
	int arr3[DynamicIndex(100)];
	//�׷��� �� �ǹ� ���°� �ƴѰ�...??

	//��.. ���� �Ǿ���.. �Ʒ��� ���� ������ �ƿ� �ȵǴ� �Ϳ��� �޶�������..
	int arr3[ReturnIndex(100)];

	const int num = 100;
	//int arr4[DynamicIndex(num)];
}