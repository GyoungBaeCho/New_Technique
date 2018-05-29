#include "stdafx.h"
#include "Function_Tool.h"

#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

/*
-----------------------------------------------------------
�ؿ�� ���� - ĳ���� : 
	data[ key ].get< T >()

-----------------------------------------------------------
�ؿ��� String ���·� ��ȯ : 
	data.dump( �� �� )
-----------------------------------------------------------
������ ��� : 
	std::ofstream out("���ϸ�.json");
	out << std::setw( �� �� ) << data;

-----------------------------------------------------------
������ �Է� : 
	std::ifstream in("���ϸ�.json");
	in >> data;

-----------------------------------------------------------
�ع��ڿ� �Ľ� : 
	1. json data = "{\"key\" : 10000"}"_json;

	2. json data = R"(
		{
				"key1" : 20000,
				"key2" : 30000
		}
	)"_json;

-----------------------------------------------------------
�ػ���� ���� �ڷ��� to JSON : ����� ���� �ڷ����� �Ű������� �޴� ��ȯ �Լ��� Overload �Ѵ�.
	json ObjToJson(const �����_����_�ڷ���& info){
		json data;
		data[key1] = info.��Ÿ���...
		data[key2] = info.��Ÿ���...
		data[key3] = info.��Ÿ���...
		return data;
	}

*/

int main(){
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
} 