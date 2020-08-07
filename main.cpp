#include <iostream>
#include <array>
#include <chrono>

#include "DataInput.h"
#include "TestDataMaker.h"
#include "DataTool.h"


using namespace std;

int main() {
	DataInput data_input;
	TestDataMaker test_data_maker;
	DataTool data_tool;
	
	//chrono::system_clock::time_point start, end;
	//chrono::high_resolution_clock::time_point start, end;

	//cout << "Make Test Data" << endl;
	//cout << "FileName" << endl;
	//
	//start = chrono::high_resolution_clock::now();

	//test_data_maker.GenerateData(1000);//テストデータ生成

	//end = chrono::high_resolution_clock::now();

	//double time = static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0);

	//cout << "Success" << endl;
	//cout << "Time:" << time << endl;

	string a = "resource/test1.log";

	vector<string> data_list;
	vector<string> data_list2;
	vector<int> dala_si;
	string tesu_a;

	
	dala_si = data_input.GetFileData(a, data_list);

	//dala_si = data_input.GetDataList();
	cout << dala_si.size() << endl;

	for (int i = 0; i < dala_si.size(); i++)
		tesu_a = to_string(dala_si[i]);
		cout << tesu_a << endl;

	return 0;
}