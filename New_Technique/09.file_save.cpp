#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

int main(){
//
//	int integer = 123456789;
//	char arr[4];
//	char *pChar;
//
///*
//	CHAR = 1byte
//	INT	 = 4byte
//
//	����Ʈ ����� ���� ���� ������.
//	byte������ int�� �����Ϸ���, int�� 4���� byte������ �ɰ��� 4���� ��� �����ؾ� �Ѵ�.
//
//	���� int�� char������ type casting �� ������ �ϳ��� �����ϰ� �Ǹ�, 4���� 1���� byte�� ������ �ǹǷ�,
//	�翬�� �����ʹ� ������ �ȴ�.
//*/
//
//	// inteager �ڷ����� char* ���·� ����ȯ �Ͽ� 4byte�� ���� �迭�� ������ �� �ֵ��� �Ѵ�.
//	pChar = (char*)(&integer);
///*
//	����ȯ���� �������� ����� �ִµ�, ����ְԵ� static_cast<>�� ���� �ʴ´�.
//
//	reinterpret_cast<>���� ���� ������ ���¸� �ٲٴ� ������ �̰��� ����ϱ⸦ �����Ѵ�.
//	���� ���������� ����ϰ� �ɰ��̴�.
//
//	pChar = (char*)(&integer);							// O
//	pChar = static_cast<char*>(&integer);				// X
//	pChar = reinterpret_cast<char*>(&integer);			// O
//*/
//
//
//	cout << *(int*)(pChar) << endl;
///*
//	cout << *(int*)(pChar) << endl;						// O
//	cout << static_cast<int*>(pChar) << endl;			// X
//	cout << *reinterpret_cast<int*>(pChar) << endl;		// O
//*/
//
//
//	pChar[0];
//	pChar[1];
//	pChar[2];
//	pChar[3]=5;
//	cout << *reinterpret_cast<int*>(pChar) << endl;
///*
//	4���� byte ��θ� ����ؾ��Ѵٴ� ���ŷ�,
//	4��° index ���� �����Ͽ� �ٽ� integer�� ����غ���, ���� �޶������� Ȯ���� �� �ִ�.
//*/
//
//	ofstream fOut;
//	fOut.open("data2.txt", std::ios::binary);
//
//	if(fOut.is_open()) cout << "Open Success" << endl;
//
//	vector<int> vnum;
//
//#define LOOP_NUM	5000
//
//	for(int i=0 ; i<LOOP_NUM ; ++i)
//		vnum.push_back(i);
//
//	for(int i=0 ; i<LOOP_NUM ; ++i){
//		fOut.write ((char*)&vnum[i], sizeof(vnum.front()));
//	//	char* pChar = reinterpret_cast<char*>(&vnum[i]);
//	//	fOut << pChar[0] << pChar[1] <<pChar[2] <<pChar[3];
//	}
//	fOut.close();
//	
//	ifstream fIn;
//	fIn.open("data2.txt", std::ios::binary);
//	if(fIn.is_open()) cout << "Open Success" << endl;
//
//	while(!fIn.eof()){
//		fIn.read(pChar, 4);
//		cout << *reinterpret_cast<int*>(pChar) << endl;
//	}
//	fIn.close();
//
//
//
	struct VECTOR{
		float x;
		float y;
		float z;
		float w;
		VECTOR(float x, float y, float z, float w){
			this->x = x;
			this->y = y;
			this->z = z;
			this->w = w;
		}
	};



	//ofstream fOut;
	//fOut.open("vector.txt", std::ios::binary);
	//if(fOut.is_open()) cout << "Open Success" << endl;

	////char* ppp = reinterpret_cast<char*>(&XMFLOAT4(1,1,1,1));
	////XMFLOAT4 pXMVec = *reinterpret_cast<XMFLOAT4*>(ppp);

	////fOut.write (reinterpret_cast<char*>(&pXMVec), sizeof(pXMVec));

	////fOut.close();
	////return 0;


	//vector<XMFLOAT4> vnum;

	//for(int i=0 ; i<10000 ; ++i)
	//	vnum.push_back(XMFLOAT4(1, 1, 1, 1));

	//for(int i=0 ; i<10000 ; ++i){
	//	fOut.write (reinterpret_cast<char*>(&vnum[i]), sizeof(vnum.front()));
	//}
	//fOut.close();
	//
	//char* pChar = nullptr;
	//ifstream fIn;
	//fIn.open("vector.txt", std::ios::binary);
	//if(fIn.is_open()) cout << "Open Success" << endl;

	//while(!fIn.eof()){
	//	fIn.read(pChar, sizeof(XMFLOAT4));
	//	XMFLOAT4 pXMVec = *reinterpret_cast<XMFLOAT4*>(pChar);
	//	cout << pXMVec.x << pXMVec.y << pXMVec.z << pXMVec.w << endl;
	//}
	//fIn.close();
}
