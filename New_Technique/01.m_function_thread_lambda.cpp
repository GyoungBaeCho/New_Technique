#include "stdafx.h"

#include <string>
#include <stdarg.h>
#include <time.h>
#include <windows.h>

#include <thread>
#include <vector>

#include <iostream>
using namespace std;

//��� �Լ��� ������� �����ϴ� ��ü
class CObject{
private:
	vector<thread*> m_vpThread;

public:
	//�������� ��ü���� �Լ�
	static void ThreadFunc(CObject* pResourceManager, int num){
		while(true){
			cout << num << endl;
			Sleep(rand()%100 + 100);
		}
	}

	//������ ���� ��ü
	void CreateThread(){
		for(int i=0 ; i<4 ; ++i){
			//���� ���ο� ������ �Լ� ��ü�� �ִ�.
			//[&](){} �� [=](){} �� �������� ������, ������� ���̴�
			m_vpThread.push_back(new thread([&](){ThreadFunc(this, i);}));
		}
	}
};


int main(){
	CObject test;
	test.CreateThread();

	while(true);
}