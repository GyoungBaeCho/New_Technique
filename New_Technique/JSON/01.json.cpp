#include "stdafx.h"
#include "Function_Tool.h"

#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
#include <gsl/gsl>

using json = nlohmann::json;

/*
-----------------------------------------------------------
※요소 접근 - 캐스팅 : 
	data[ key ].get< T >()

-----------------------------------------------------------
※예쁜 String 형태로 변환 : 
	data.dump( 탭 수 )
-----------------------------------------------------------
※파일 출력 : 
	std::ofstream out("파일명.json");
	out << std::setw( 탭 수 ) << data;

-----------------------------------------------------------
※파일 입력 : 
	std::ifstream in("파일명.json");
	in >> data;

-----------------------------------------------------------
※문자열 파싱 : 
	1. json data = "{\"key\" : 10000"}"_json;

	2. json data = R"(
		{
				"key1" : 20000,
				"key2" : 30000
		}
	)"_json;

-----------------------------------------------------------
※사용자 정의 자료형 to JSON : 사용자 정의 자료형을 매개변수로 받는 변환 함수를 Overload 한다.
	json ObjToJson(const 사용자_정의_자료형& info){
		json data;
		data[key1] = info.기타등등...
		data[key2] = info.기타등등...
		data[key3] = info.기타등등...
		return data;
	}

*/

class CTest 
{
public:
	void Function() const {
		int a = 0;
		a += 10;
		std::cout << "const Funciton" << std::endl;
//		num += 10;
	}
	void Function(){
		int a = 0;
		a += 10;
		std::cout << "normal Funciton" << std::endl;
	}
	int len() {
		std::cout << "haha" << std::endl;
		return 10;
	}
private:
	int num = 0;
};


void func(const gsl::span<int>& r) {
	std::cout << r.size() << " - " << r.size_bytes() << std::endl;
}


int main() {
	for (__int32 i=1; i ; i<<=1) {
		std::cout << i << std::endl;
	}

	milliseconds mil = 100ms;
	seconds sec = 100s;

	int* p = new int[100];
	std::cout << sizeof(p) << std::endl;

	int arr[100];
	std::cout << sizeof(arr) << std::endl;
	func({ arr, 200});
	std::cout << std::endl;

	CTest a;
	a.Function();

	const CTest b;
	b.Function();

	//We go get it la!
	//Branch_Test Updated!!
	//Branch_Test Updated!!2
	//Branch_Test Updated!!3

	json jData;
	jData["key1"] = 100;
	jData["key2"] = 101;
	jData["key3"] = 102;
	jData["array1"] = {4, 3, 2, 1, 5, 3, 10};
	jData["obect1"] = { {"key1", 1000}, {"key2", 2000} };

	std::cout << std::setw(4) << jData;

	std::ofstream output_file("json_data.json");
	output_file << std::setw(4) << jData;
	output_file.close();

	json jData2;
	std::ifstream input_file("json_data.json");
	input_file >> jData2;
	input_file.close();

	std::cout << std::setw(4) << jData2 << std::endl;
	

	static_assert(1, "gogogo");
} 