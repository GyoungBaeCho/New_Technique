#include "stdafx.h"
#include "Function_Tool.h"

system_clock::time_point startTime;
duration<double> passedTime;

void BeginTimer(){
	startTime = system_clock::now();
}

void EndTimer(){
	passedTime = system_clock::now() - startTime;
	cout << "���� �ð� : " << passedTime.count()  << endl;
}

