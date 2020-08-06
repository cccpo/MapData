#include <iostream>
#include <array>
#include <chrono>

#include "DataInput.h"
#include "TestDataMaker.h"


using namespace std;

int main() {
	DataInput data_input;
	TestDataMaker test_data_maker;
	
	chrono::system_clock::time_point start, end;

	cout << "Make Test Data" << endl;
	cout << "FileName" << endl;
	
	start = chrono::system_clock::now();

	test_data_maker.GenerateData(1000);

	end = chrono::system_clock::now();

	double time = static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0);

	cout << "Success" << endl;
	cout << "Time:" << time << endl;

	//vector<string> ioVectorDatas;
	/*data_input.GetFileData(a, ioVectorDatas);

	cout << ioVectorDatas.size() << endl;

	for (int i = 0; i < ioVectorDatas.size(); i++)
		cout << ioVectorDatas[i] << endl;*/

	return 0;
}