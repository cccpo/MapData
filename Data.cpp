#include "Data.h"

Data::Data() :mVectorDates(10001, list<int>(11)),mLos(10001) {

}

Data::~Data() {

}

//�e�X�g�f�[�^�������s�֐�
const void Data::GenerateTestData(string& inFileName) {
	cout << "Make Test Data" << endl;

	test_data_maker.GenerateTestDataCSV(inFileName, 10000);

	cout << "Success" << endl;
}

//CSV�f�[�^�ǎ���s�֐�
const void Data::LoadTestData(string& inFileName) {
	chrono::high_resolution_clock::time_point start, end;
	
	cout << "Load Data..." << endl;

	start = chrono::high_resolution_clock::now();//�v���J�n
	
	mVectorDates = data_input.LoadCSVData(inFileName);//CSV�t�@�C������f�[�^�𒊏o���A�����o�ϐ��Ɋi�[
	
	//mLos = data_input.LoadCSVDataInt(inFileName);

	//cout <<mVectorDates.size()<<endl;
	end = chrono::high_resolution_clock::now();//�v���I��

	double time = static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0);
	cout << "Time:" << time << endl;

	cout << "Loading Completed" << endl;

	start = chrono::high_resolution_clock::now();//�v���J�n
	
	ExtractPlayerCourceData(mVectorDates);

	end = chrono::high_resolution_clock::now();//�v���I��

	time = static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0);
	cout << "Time:" << time << endl;


}

const void Data::ExtractPlayerCourceData(vector<list<int>>& inDate) {
	cout << "Extract Data..." << endl;

	mPriorityDates = data_sort.ExtractData(inDate);

	string output_file_name = "AfterData3.csv";

	data_tool.MakeResultData(mPriorityDates, output_file_name);

	cout << "Data Extraction Completed" << endl;
}