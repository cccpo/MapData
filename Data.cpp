#include "Data.h"

Data::Data() :mVectorDates(10001, vector<string>(11)) {

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
	cout << "Load Data..." << endl;

	mVectorDates = data_input.LoadCSVData(inFileName);//CSV�t�@�C������f�[�^�𒊏o���A�����o�ϐ��Ɋi�[

	cout << "Loading Completed" << endl;

	mSortVectorDates = data_sort.DeleteKeyCategory(mVectorDates);//�v���C���[�l�[���̍폜
	
	cout << "Extract Data..." << endl;

	mPriorityDates = data_sort.ExtractData(mSortVectorDates);

	cout << "Data Extraction Completed" << endl;

	string output_file_name = "AfterData2.csv";
	
	data_tool.MakeResultData(mPriorityDates, output_file_name);

}