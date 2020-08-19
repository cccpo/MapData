#include "Data.h"

Data::Data() :mVectorDates(10001, vector<string>(11)) {

}

Data::~Data() {


	//mSortVectorDates.clear();
	//mPriorityDates.clear();
}

//テストデータ生成実行関数
const void Data::GenerateTestData(string& inFileName) {
	cout << "Make Test Data" << endl;

	test_data_maker.GenerateTestDataCSV(inFileName, 10000);

	cout << "Success" << endl;
}

//CSVデータ読取実行関数
const void Data::LoadTestData(string& inFileName) {
	cout << "Load Test Data" << endl;

	mVectorDates = data_input.LoadCSVData(inFileName);//CSVファイルからデータを抽出

	mSortVectorDates = data_sort.DeleteKeyCategory(mVectorDates);//プレイヤーネームの削除
	vector<vector<string>>().swap(mSortVectorDates);

	
	mPriorityDates = data_sort.ExtractData(mSortVectorDates);
	
	data_tool.MakeResultData(mPriorityDates,"AfterData.csv");
	vector<vector<string>>().swap(mPriorityDates);


	cout << "Success" << endl;
}