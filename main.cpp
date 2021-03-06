#include <iostream>
#include <chrono>


#include "DataSort.h"
#include "Data.h"

#define DBG_ASSERT()

using namespace std;



int main() {
	Data data;

	chrono::high_resolution_clock::time_point start, end;

	string file_name = "BeforeData.csv";//読み込む対象

//テストデータ生成
	//start = chrono::high_resolution_clock::now();//計測開始
	//data.GenerateTestData(file_name);//テストデータ生成実行関数
	//end = chrono::high_resolution_clock::now();//計測終了
	//double time = static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0);
	//cout << "Time:" << time << endl;

//テストデータ読み込みと抽出結果の出力まで
	start = chrono::high_resolution_clock::now();//計測開始
	data.LoadTestData(file_name);//CSVデータの読み込み実行関数
	end = chrono::high_resolution_clock::now();//計測終了

	double time = static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0);
	cout << "[main]Time:" << time << endl;

	//cout << "Please Input Something";
	//int input;
	//std::cin >> input;

	return 0;
}