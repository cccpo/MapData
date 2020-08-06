#include <iostream>
#include <array>

#include "DataInput.h"
#include "TestDataMaker.h"


using namespace std;

int main() {
	DataInput data_input;
	TestDataMaker test_data_maker;

	cout << "Make Test Data" << endl;
	
	test_data_maker.GenerateData();

	cout << "Success" << endl;

	vector<string> ioVectorDatas;
	data_input.GetFileData("Test1.log", ioVectorDatas);

	cout << ioVectorDatas.size() << endl;

	for (int i = 0; i < ioVectorDatas.size(); i++)
		cout << ioVectorDatas[i] << endl;

	return 0;
}