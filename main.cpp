#include <iostream>
#include <array>
#include <chrono>


#include "DataSort.h"
#include "Data.h"

using namespace std;



int main() {
	Data data;

	chrono::high_resolution_clock::time_point start, end;

	string file_name = "BeforeData.csv";

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

//�i�[�����e�X�g�f�[�^���m�F����
	//data_list = data_input.GetPlayerCourseData(1);
	//
	//for (int i = 0; i < data_list.size(); i++) {
	//	tesu_a = to_string(dala_si[i]);
	//	cout << data_list.at(i) << endl;
	//}

	return 0;
}