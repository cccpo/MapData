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

	string file_name = "test21SS.csv";

//�e�X�g�f�[�^����
	cout << "Make Test Data" << endl;
	
	start = chrono::high_resolution_clock::now();//�v���J�n
	test_data_maker.GenerateTestDataCSV(file_name, 10000);
	end = chrono::high_resolution_clock::now();//�v���I��

	double time = static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0);
	cout << "Success" << endl;
	cout << "Time:" << time << endl;

	vector<string> data_list;
	vector<string> data_list2;
	vector<int> dala_si;
	string tesu_a;

//�e�X�g�f�[�^�ǂݍ���
	//#TODO ����t�H���_���̃f�[�^�����X�g�ɒǉ�����
	string a = "resource/test1.log";
	
	dala_si = data_input.GetFileData(a, data_list);

	//for (int i = 0; i < dala_si.size(); i++)
		//tesu_a = to_string(dala_si[i]);
		//cout << tesu_a << endl;

	return 0;
}