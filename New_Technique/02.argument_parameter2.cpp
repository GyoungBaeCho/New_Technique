#include "stdafx.h"

#include <iostream>
using namespace std;
#include <string>
#include <stdarg.h>
#include <time.h>


template<typename...Args>
void Function(int count, Args...args){
	va_list list;

	//C�� �������ڿ� �������� ���ø��� �ٸ� �����̴�.

	//�Ʒ��� ������ va_start�� �Ķ���ͷ� �ѱ�� �߸��� ���� ��µȴ�.
	int num_of_args = sizeof...(args);
	
	va_start(list, num_of_args);
//	va_start(list, count);
	for(int i=0 ; i<num_of_args ; ++i) 
		cout << va_arg(list, int) << endl;
	va_end(list);
}

int main(){

//	#define NUMARGS(...)  (sizeof((int[]){__VA_ARGS__})/sizeof(int))
//	#define CHECK1(...) { printf(__VA_ARGS__); }  
//	#define NUMARGS2(...)  	int a[]{__VA_ARGS__}; 

//	int a[]{10, 10};
//	sizeof(int[]{10, 10})/sizeof(int);

	Function(5, 1, 2, 3, 4, 5);
}
