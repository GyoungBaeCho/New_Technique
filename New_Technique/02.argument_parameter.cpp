#include "stdafx.h"

#include <iostream>
using namespace std;
#include <string>
#include <stdarg.h>
#include <time.h>

void HandlData(int i){ cout << i << endl; }
void HandlData(string s){ cout << s << endl; }
//�ƹ��͵� ���� �ʾ��� ���
void Print(){ }

//�������ڸ� ���� �Լ�
template<typename  Ty, typename...Args>
void Print(Ty ty, Args...args)
{
	HandlData(ty);

	Print(args...);
}

int main(){

	Print(10, 20, 30, 40, 50, 60, 70, "Hey Hey!", "�ȳ��ϼ���!");
}