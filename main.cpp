#include <iostream>
#include <array>
#include <chrono>

//#include "DataInput.h"
#include "TestDataMaker.h"
#include "DataTool.h"
#include "DataSort.h"
#include "Data.h"

using namespace std;



int main() {
	Data data;
	//DataInput data_input;
	TestDataMaker test_data_maker;
	DataTool data_tool;
	DataSort data_sort;


	
	chrono::high_resolution_clock::time_point start, end;

	string file_name = "testdata11000.csv";
	//string file_path = data_tool.SetFilePath("testdata110.csv");

	//start = chrono::high_resolution_clock::now();//�v���J�n
	//data.GenerateTestData(file_name);//�e�X�g�f�[�^�������s�֐�
	//end = chrono::high_resolution_clock::now();//�v���I��
	//double time = static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0);
	//cout << "Time:" << time << endl;
	
	//vector<string> data_list;
	//vector<string> data_list2;
	//vector<int> dala_si;
	//string tesu_a;
	//string player_name = "PlayerA";

//�e�X�g�f�[�^�ǂݍ���
	start = chrono::high_resolution_clock::now();//�v���J�n
	data.LoadTestData(file_name);//CSV�f�[�^�̓ǂݍ��ݎ��s�֐�
	end = chrono::high_resolution_clock::now();//�v���I��

	double time = static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0);
	cout << "Time:" << time << endl;

	//if (data_input.IsExitPlayerID(player_name)) {
	//	data_list = data_input.SearchPlayerData(player_name);
	//}

	//data_list = data_input.SearchPlayerData(player_name);
	//cout << data_input.GetPlayIDData(1, 1);

	cout << data.mVectorDates.at(0).at(1) << endl;

	//data_input.Sort();

	//cout << data_sort.mSortVectorDates.size() << endl;
	//cout << data_sort.mSortVectorDates.at(0).size() << endl;
	//cout << data_sort.mSortVectorDates.at(1).at(1) << endl;

//�i�[�����e�X�g�f�[�^���m�F����
	//data_list = data_input.GetPlayerCourseData(1);
	//
	//for (int i = 0; i < data_list.size(); i++) {
	//	tesu_a = to_string(dala_si[i]);
	//	cout << data_list.at(i) << endl;
	//}

	return 0;
}