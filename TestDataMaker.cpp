#include "TestDataMaker.h"


TestDataMaker::TestDataMaker(){
	//GenerateData();
}

TestDataMaker::~TestDataMaker() {
	
}

void TestDataMaker::GeneratePlayerID(char* inPlayerID, const int inLength) {

}

//データのランダム生成
const void TestDataMaker ::GenerateData(const int& inNumOfData) {
	random_device rnd;
	mt19937 mt(rnd());
	uniform_int_distribution<int> type(0, 9);//0～9の範囲で乱数発生
	uniform_int_distribution<int> second_number(2, 4);//2～4の範囲で乱数発生
	uniform_int_distribution<int> third_number(0, 1);//0～1の範囲で乱数発生
	
	const string& folder_name = "resource/";
	const string& test_1 = "test";
	const string& test_3 = ".log";

	for (int number = 0; number < inNumOfData; number++) {
		string test_number = to_string(number);
		string test_data_name = folder_name + test_1 + test_number + test_3;


		ofstream test_file(test_data_name);//出力形式

		if (test_file.fail()) {
			cout << "Error:Can't read text" << endl;
		}

		test_file << "PlayerID:Player" << number << endl;

		test_file << "PlayerCourse:";
		for (int number = 0; number < mDataSize; ++number) {
			if (number == 0) {
				mData[number] = type(mt);
			}
			else {
				if (mData[number - 1] == 0) {
					mData[number] = mData[number - 1] + third_number(mt);
				}
				else if (mData[number - 1] == 9) {
					mData[number] = mData[number - 1] - third_number(mt);
				}
				else
					mData[number] = mData[number - 1] + second_number(mt) - 3;

			}
		
			if (number == 9) {
				test_file << "{" << number << "," << mData[number] << "}";
			}else {
				test_file << "{" << number << "," << mData[number] << "}.";
			}

		}

		test_file.close();


		cout << test_data_name << endl;
	}



}

//データのランダム生成(CSVファイルに書き込み)
//inFileName ファイル名
//inNumOfData データ数
const void TestDataMaker::GenerateTestDataCSV(string inFileName, int inNumOfData) {
	random_device rnd;
	mt19937 mt(rnd());
	uniform_int_distribution<int> table_1(0, 9);//0～9の範囲で乱数発生
	uniform_int_distribution<int> table_2(2, 4);//2～4の範囲で乱数発生
	uniform_int_distribution<int> table_3(0, 1);//0～1の範囲で乱数発生

	string file_path = data_tool.SetFilePath(inFileName);

	ofstream test_csv_file(file_path);//出力形式
	test_csv_file << "PlayerID" << "," << "PlayerCource" << endl;

	for (int row_number = 0; row_number < inNumOfData; ++row_number) {
		string test_number = to_string(row_number);
	
		test_csv_file << "Player" << row_number << ",";

	
		for (int column_number = 0; column_number < mDataSize; ++column_number) {
			if (column_number == 0) {
				mData[column_number] = table_1(mt);
			}else {
				if (mData[column_number - 1] == 0) {
					mData[column_number] = mData[column_number - 1] + table_3(mt);
				}else if (mData[column_number - 1] == 9) {
					mData[column_number] = mData[column_number - 1] - table_3(mt);
				}else {
					mData[column_number] = mData[column_number - 1] + table_2(mt) - 3;
				}
			}

		test_csv_file << "{" << column_number << "." << mData[column_number] << "},";
				
		}

		test_csv_file << endl;		
		
	}
	test_csv_file.close();
}