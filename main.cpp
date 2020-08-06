#include <iostream>
#include <array>

#include "DataInput.h"
#include "TestDataMaker.h"


using namespace std;

int main() {
	DataInput data_input;
	TestDataMaker test_data_maker;

	string a = "resource/Test3.log";

	cout << "Make Test Data" << endl;
	cout << "FileName" << endl;
	test_data_maker.GenerateData(1000);

	cout << "Success" << endl;

	vector<string> ioVectorDatas;
	data_input.GetFileData(a, ioVectorDatas);

	cout << ioVectorDatas.size() << endl;

	for (int i = 0; i < ioVectorDatas.size(); i++)
		cout << ioVectorDatas[i] << endl;

	return 0;
}