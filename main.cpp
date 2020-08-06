#include <iostream>
#include <array>

#include "DataInput.h"
#include "TestDataMaker.h"


using namespace std;

int main() {
	DataInput data_input;
	TestDataMaker test_data_maker;

	///*cout << "Test Case" << endl;*/
	//array<int,10> player_route=data_input.GetPlayerRoute();
	//
	//for (int i = 0; i < 10; i++) {
	//	cout << player_route[i]<<",";
	//}

	//cout << "Make Test Data" << endl;
	//
	//test_data_maker.GenerateData();

	//cout << "SuccessSS" << endl;

	vector<string> ioVectorDatas;
	data_input.GetFileData("test.txt", ioVectorDatas);

	cout << ioVectorDatas.size() << endl;

	for (int i = 0; i < ioVectorDatas.size(); i++)
		cout << ioVectorDatas[i] << endl;

	return 0;
}