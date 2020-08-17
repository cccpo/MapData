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


	
	chrono::high_resolution_clock::time_point start, end;

	string file_name = "testdata110.csv";
	string file_path = data_tool.SetFilePath("testdata110.csv");

//テストデータ生成
	{
		//cout << "Make Test Data" << endl;

		//start = chrono::high_resolution_clock::now();//計測開始
		//test_data_maker.GenerateTestDataCSV(file_name, 10000);
		//end = chrono::high_resolution_clock::now();//計測終了

		//double time = static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0);
		//cout << "Success" << endl;
		//cout << "Time:" << time << endl;
	}
//End

	vector<string> data_list;
	vector<string> data_list2;
	vector<int> dala_si;
	string tesu_a;
	string player_name = "PlayerA";

//テストデータ読み込み
	//#TODO 同一フォルダ内のデータをリストに追加する
	//string a = "resource/test1.log";
	//
	//dala_si = data_input.GetFileData(a, data_list);

	cout << "Load Test Data" << endl;
	start = chrono::high_resolution_clock::now();//計測開始
	data_input.LoadCSVData(file_name);//CSVデータの読み込み
	end = chrono::high_resolution_clock::now();//計測終了

	//double time = static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0);
	//cout << "Success" << endl;
	//cout << "Time:" << time << endl;

	//if (data_input.IsExitPlayerID(player_name)) {
	//	data_list = data_input.SearchPlayerData(player_name);
	//}

	//data_list = data_input.SearchPlayerData(player_name);
	//cout << data_input.GetPlayIDData(1, 1);
	//data_list = data_input.GetPlayerCourseData(1);
	//
	//for (int i = 0; i < data_list.size(); i++) {
	//	tesu_a = to_string(dala_si[i]);
	//	cout << data_list.at(i) << endl;
	//}

	return 0;
}