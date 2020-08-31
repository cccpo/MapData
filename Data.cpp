#include "Data.h"

Data::Data() :mVectorDates(10001, list<int>(11)),mLos(10001) {

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
	chrono::high_resolution_clock::time_point start, end;
	
	cout << "Load Data..." << endl;

	start = chrono::high_resolution_clock::now();//計測開始
	
	mVectorDates = data_input.LoadCSVData(inFileName);//CSVファイルからデータを抽出し、メンバ変数に格納
	
	//mLos = data_input.LoadCSVDataInt(inFileName);

	//cout <<mVectorDates.size()<<endl;
	end = chrono::high_resolution_clock::now();//計測終了

	double time = static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0);
	cout << "Time:" << time << endl;

	cout << "Loading Completed" << endl;

	start = chrono::high_resolution_clock::now();//計測開始
	
	ExtractPlayerCourceData(mVectorDates);

	end = chrono::high_resolution_clock::now();//計測終了

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