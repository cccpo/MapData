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

	for (int data_column = 0; data_column < mSortVectorDates.size(); data_column++) {
		for (int data_row = 0; data_row < mSortVectorDates.at(data_column).size(); data_row++) {
			//cout << mSortVectorDates.at(data_column).at(data_row);
		}
	//cout << endl;
	}

	/*cout << mSortVectorDates.size() << endl;
	cout << mSortVectorDates.at(0).size() << endl;*/

	return mSortVectorDates;
}

vector<vector<string>> DataSort::ExtractData(vector<vector<string>> inDataList) {
	vector<vector<string>> list(10001, vector<string>(12));
	int count = 0;
	int column = 0;
	int column_count=0;

	int data_column = 4;

	//cout << inDataList.size() << endl;
	
	//list.resize(inDataList.size());

	while (data_column<10000) {
		for (int i = 0; i < inDataList.size(); i++) {

			//for (int data_column = 0; data_column < mSortVectorDates.size(); data_column++) {
			//	
			if (inDataList.at(data_column) == inDataList.at(i) && data_column != i) {
				cout << "No." <<data_column + 1<< "'s Pair: ";
				
				cout << "No."<<i +1<<endl;
				++count;
				list.at(column_count) = inDataList.at(i);
				list.at(column_count).push_back(to_string(i));

				++column_count;
			}

			

				
			
			

			//}



		}

		

		

		if (count > 1) {
			//cout << "No." << data_column << ":";
			//list.at(column) = mSortVectorDates.at(i);
			string number = to_string(count);
			list.at(column).push_back(number);
			cout << "[CODE:S]" << count << endl;
			cout << endl;
		
			//inDataList.erase(inDataList.begin() + i);
			count = 0;
		}
		else {
			//cout << "[CODE:F]Nothing" << endl;
		}

		
		++data_column;
	}

	//1個以上あれば
	//if (count > 1) {
	//	//list.at(column) = mSortVectorDates.at(i);
	//	/*string number = to_string(count);
	//	list.at(column).push_back(number);*/
	//	cout <<"[CODE:S]" <<count << endl;
	//	//++column;
	//}
	//else {
	//	cout << "[CODE:F]Nothing" << endl;
	//}

	//count = 0;

	return inDataList;
}
