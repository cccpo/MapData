#include <iostream>
#include <chrono>


#include "DataSort.h"
#include "Data.h"

using namespace std;



int main() {
	Data data;

	chrono::high_resolution_clock::time_point start, end;

	string file_name = "BeforeData_2.csv";//�ǂݍ��ޑΏ�

	//start = chrono::high_resolution_clock::now();//�v���J�n
	//data.GenerateTestData(file_name);//�e�X�g�f�[�^�������s�֐�
	//end = chrono::high_resolution_clock::now();//�v���I��
	//double time = static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0);
	//cout << "Time:" << time << endl;

//�e�X�g�f�[�^�ǂݍ��݂Ɛ����܂�
	start = chrono::high_resolution_clock::now();//�v���J�n
	data.LoadTestData(file_name);//CSV�f�[�^�̓ǂݍ��ݎ��s�֐�
	end = chrono::high_resolution_clock::now();//�v���I��

	//double time = static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0);
	//cout << "Time:" << time << endl;

//�i�[�����e�X�g�f�[�^���m�F����

	return 0;
}