#include "DataSort.h"

DataSort::DataSort() {

}

DataSort::~DataSort() {

}

const vector<vector<string>> DataSort::DeleteKeyCategory(vector<vector<string>>& inDataList) {
	vector<vector<string>> sort_dates;//データを格納するvector

	sort_dates = inDataList;

	sort_dates.erase(sort_dates.begin());//1行目の消去,要素の削除
	
	 //プレイヤーネームを削除
	for(int  data_column = 0; data_column < sort_dates.size(); ++data_column){
		sort_dates.at(data_column).erase(sort_dates.at(data_column).begin());
	}

	return sort_dates;
}

const vector<list<int>> DataSort::IntDeleteKeyCategory(vector<vector<string>>& inDataList) {
	vector<list<int>> sort_dates;//データを格納するvector
	vector<list<int>>::iterator sort_dates_iretator = sort_dates.begin();
	list<int>::iterator list_iretator;


	//cout << "Dele";
	//sort_dates = inDataList;

	//cout << inDataList.at(0).at(0) << endl;
	
	inDataList.erase(inDataList.begin());//1行目の消去

	//cout << inDataList.at(0).at(0) << endl;

	
	 //プレイヤーネームを削除
	for (vector<vector<string>> ::iterator ks_itt = inDataList.begin(); ks_itt != inDataList.end(); ++ks_itt) {
		vector<string>::iterator iterVec = (*ks_itt).begin();
		iterVec->erase();

		list_iretator = (*sort_dates_iretator).begin();
		for (iterVec; iterVec != (*ks_itt).end(); ++iterVec) {
			//*list_iretator = stoi(*iterVec);


		/*	cout << *iterVec;*/
			//++list_iretator;*/
		}
		//cout << endl;
	}


	//cout << inDataList.at(0).size();

	 //プレイヤーネームを削除
	for (int data_column = 0; data_column < sort_dates.size(); ++data_column) {
		sort_dates.at(data_column).erase(sort_dates.at(data_column).begin());
	}

	return sort_dates;
}

//データの抽出を行う
const vector<list<int>> DataSort::ExtractData(vector<vector<int>>& inDataList) {
	vector<list<int>> result_list(10000, list<int>(10));
	
	vector<int> pair_list;//組み合わせが見つかった経路を格納する

	//イテレータ設定
	vector<vector<int>>::iterator m_vector_iterator = inDataList.begin();//引数
	vector<vector<int>>::iterator m_vector_iterator2nd;


	vector<int>::iterator mm_vector_iterator;
	vector<int>::iterator mm_vector_iterator2nd;
	vector<int>::iterator mm_vector_iterator3rd = (*m_vector_iterator).begin();

	
	list<int> except_number_list;//除外リスト


	vector<string>::iterator it;

	vector<list<int>>::iterator result_list_iretator = result_list.begin();
	list<int> rresult_list_iretator;

	int i_count=0;
	int pair_count = 0;//ペア数をカウントする
	int result_list_column=0;//CSVファイルの何行目にデータをカウントするのかを示す
	int num_of_pairs = 0;//複数人使用した経路数をカウントする

	int data_column = 0;

	//cout << inDataList.size() << endl;
	//cout << *mm_vector_iterator3rd << endl;

	//cout << result_list.size() << endl;
	//cout << result_list.at(1).size() << endl;

	int NumOfRoop;
	int AllRoop = 0;
	//データの行数分回す
	for (m_vector_iterator; m_vector_iterator != inDataList.end(); ++m_vector_iterator) {

		NumOfRoop = 0;

		//除外リストに入っているかを確認
		if (!data_tool.IsExitNumber(except_number_list, data_column)) {
			//cout << data_column << endl;

			m_vector_iterator2nd = m_vector_iterator+1;
			//除外リストに含まれていない場合処理を行う
			for (m_vector_iterator2nd; m_vector_iterator2nd != inDataList.end();++m_vector_iterator2nd) {
				
				//合致する経路があれば抽出、同一のペア数をカウント
				if (*m_vector_iterator == *m_vector_iterator2nd) {
					
					//合致した値を確認する
					for (mm_vector_iterator = (*m_vector_iterator2nd).begin(); mm_vector_iterator != (*m_vector_iterator2nd).end();++mm_vector_iterator) {
						//cout << *mm_vector_iterator;
					}
					cout << *mm_vector_iterator2nd << endl;

					pair_list.emplace_back(((data_column + 1) + NumOfRoop));//ペアリストに追加
					//cout << "Data_column(" << i_count <<")+NumofRoop"<< NumOfRoop << endl;;
					//except_number_list.emplace_back((data_column + 1) + NumOfRoop);//除外リストに追加
					++pair_count;
					//cout << "Pair:" << pair_count << endl;;
					//cout << endl;
					++i_count;
				}
				
				++NumOfRoop;
			}

			
			

			//ペア数が~個以上であればファイルに追加
			if (pair_count >= 3) {

				//for (int j = 0; j < inDataList.at(data_column).size(); ++j)
				//*result_list_iretator = *m_vector_iterator;
				//rresult_list_iretator = (*result_list_iretator).begin();

				//string number = to_string(pair_count);
				cout << "No." << data_column << "'s Pair: ";

				for (int l=0; l < pair_list.size(); ++l) {
					string s_pair = to_string(pair_list.at(l));
					//result_list.at(result_list_column).emplace_back(to_string(l));//末尾に同一のプレイヤーを追加
					cout << "No." << pair_list.at(l)<<" ";
				}

				cout << endl;

				//inDataList.erase(inDataList.begin() + i);
				//result_list.at(result_list_column).emplace_back(to_string(pair_count));

				//result_list_iretator = result_list_iretator->emplace_front(pair_count);//イテレータを最前部
				//it = result_list.at(result_list_column).insert(it, to_string(pair_count));//ペアのカウント

				//cout << result_list.at(data_column).size() << endl;
				//result_list.at(data_column).resize(11);
				//cout << result_list.at(data_column).size() << endl;

				++result_list_iretator;

			
				++num_of_pairs;
				++result_list_column;//CSVファイルの改行

			}

			//vector<string>().shrink_to_fit();

			++data_column;
			i_count = 0;
			pair_count = 0;
			pair_list.clear();
			//cout << "data_column:" << data_column << endl;//ループ回数の確認
			//cout << "NumfOfRoop:" << NumOfRoop << endl;//ループ回数の確認
		}
		
		result_list.resize(num_of_pairs);//ペア数分の行数にリサイズ
		AllRoop += NumOfRoop;//AllRoopに加算
	}
	cout << AllRoop<<endl;//全ループ回数の確認
	

	return result_list;
}
