#include "Data.h"

Data::Data() :mVectorDates(10001, vector<string>(11)) {

}

Data::~Data() {

}

//テストデータ生成実行関数
const void Data::GenerateTestData(string& inFileName) {
	cout << "Make Test Data" << endl;

	test_data_maker.GenerateTestDataCSV(inFileName, 10000);

	cout << "Success" << endl;
}

//CSVデータ読取実行関数
const void Data::LoadTestData(string& inFileName) {
	cout << "Load Data..." << endl;

	mVectorDates = data_input.LoadCSVData(inFileName);//CSVファイルからデータを抽出し、メンバ変数に格納

	cout << "Loading Completed" << endl;

	mSortVectorDates = data_sort.DeleteKeyCategory(mVectorDates);//プレイヤーネームの削除
	
	cout << "Extract Data..." << endl;

	mPriorityDates = data_sort.ExtractData(mSortVectorDates);

	cout << "Data Extraction Completed" << endl;

	string output_file_name = "AfterData2.csv";
	
	data_tool.MakeResultData(mPriorityDates, output_file_name);

}