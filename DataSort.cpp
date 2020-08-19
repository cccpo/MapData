#include "DataSort.h"

DataSort::DataSort():mSortVectorDates(10001, vector<string>(11)) {

}

DataSort::~DataSort() {

}

vector<vector<string>> DataSort::DeleteKeyCategory(vector<vector<string>> inDataList) {
	mSortVectorDates = inDataList;

	mSortVectorDates.erase(mSortVectorDates.begin());//1行目の消去,要素の削除
	

	 //cout << mSortVectorDates.at(0).at(0);

	 //プレイヤーネームを削除
	for(int  data_column = 0; data_column < mSortVectorDates.size(); ++data_column){
		mSortVectorDates.at(data_column).erase(mSortVectorDates.at(data_column).begin());
	}

	for (int data_column = 0; data_column < mSortVectorDates.size(); ++data_column) {
		for (int data_row = 0; data_row < mSortVectorDates.at(data_column).size(); ++data_row) {
			//cout << mSortVectorDates.at(data_column).at(data_row);
		}
	//cout << endl;
	}

	/*cout << mSortVectorDates.size() << endl;
	cout << mSortVectorDates.at(0).size() << endl;*/

	return mSortVectorDates;
}

vector<vector<string>> DataSort::ExtractData(vector<vector<string>> inDataList) {
	vector<vector<string>> result_list(10001, vector<string>(12));
	vector<string> pair_list;
	
	vector<int> except_number_list;
	vector<string>::iterator it;


	int count = 0;
	int column = 0;
	int result_list_column=0;
	int num_of_pairs = 0;

	int data_column = 4;

	while (data_column<10000) {
		//if (!data_tool.IsFindVec(except_number_list, data_column)) {
			for (int i = 0; i < inDataList.size(); ++i) {
				//合致する経路があれば抽出する
				if (inDataList.at(data_column) == inDataList.at(i) && data_column != i &&
					!data_tool.IsFindVec(except_number_list, data_column)) {

					pair_list.push_back(to_string(i));
					except_number_list.push_back(i);
					++count;
				}


					//該当する番号を追加
					//it = result_list.at(result_list_column).begin();//
					//it = result_list.at(result_list_column).insert(it, to_string(data_column));

					//result_list.at(result_list_column).emplace_back(to_string(i));//末尾に同一のプレイヤーを追加

					//it = result_list.at(result_list_column).begin();//
					//it = result_list.at(result_list_column).insert(it, to_string(count));

				


				
			}
		//}
			//ペア数が~個以上であればファイルに追加
			if (count >= 3) {

				for (int j = 0; j < inDataList.at(data_column).size(); ++j)
					result_list.at(result_list_column).at(j) = inDataList.at(data_column).at(j);


				string number = to_string(count);
				//cout << "No." << data_column << "'s Pair: ";
				
				for (int l=0; l < pair_list.size(); ++l) {
					//string s_pair = to_string(pair_list.at(l));
					//result_list.at(result_list_column).emplace_back(to_string(l));//末尾に同一のプレイヤーを追加
					//cout << "No." << pair_list.at(l)<<" ";
				}
			
				//cout << endl;
		
				//inDataList.erase(inDataList.begin() + i);
				it = result_list.at(result_list_column).begin();//
				it = result_list.at(result_list_column).insert(it, to_string(count));
				
				//cout << result_list.at(data_column).size() << endl;
				result_list.at(data_column).resize(11);
				//cout << result_list.at(data_column).size() << endl;

				
				++num_of_pairs;
				++result_list_column;//CSVファイルの改行
				
			}

		pair_list.clear();//ペアリストのクリア
		//vector<string>().swap(pair_list);
		++data_column;
		count = 0;
	}
	/*cout <<"Pairs:" <<num_of_pairs << endl;

	cout << result_list.size() << endl;*/
	//cout << result_list.at(0).size() << endl;

	result_list.resize(num_of_pairs);

	//cout << result_list.size() << endl;


	//sort(result_list.begin(), result_list.end(), [](const vector<int>& alpha, const vector<int>& beta) {return alpha[0] < beta[0]; });

	return result_list;
}
