#include "DataSort.h"

DataSort::DataSort() {

}

DataSort::~DataSort() {

}

const vector<vector<string>> DataSort::DeleteKeyCategory(vector<vector<string>>& inDataList) {
	vector<vector<string>> sort_dates;//�f�[�^���i�[����vector

	sort_dates = inDataList;

	sort_dates.erase(sort_dates.begin());//1�s�ڂ̏���,�v�f�̍폜
	
	 //�v���C���[�l�[�����폜
	for(int  data_column = 0; data_column < sort_dates.size(); ++data_column){
		sort_dates.at(data_column).erase(sort_dates.at(data_column).begin());
	}

	return sort_dates;
}

//�f�[�^�̒��o���s��
const vector<vector<string>> DataSort::ExtractData(vector<vector<string>>& inDataList) {
	vector<vector<string>> result_list(10001, vector<string>(12));
	vector<string> pair_list;
	
	vector<int> except_number_list;
	vector<string>::iterator it;

	int i_count=0;
	int pair_count = 0;
	int result_list_column=0;
	int num_of_pairs = 0;

	int data_column = 0;

	//�f�[�^�̍s������
	while (data_column < inDataList.size()){
		//���O���X�g�Ɋ܂܂�Ă��Ȃ��ꍇ�������s��
		if (!data_tool.IsExitNumber(except_number_list, data_column)) {
			while ((data_column + 1) + i_count < inDataList.size()) {
				//���v����o�H������Β��o����
				if (inDataList.at(data_column) == inDataList.at((data_column + 1) + i_count)) {
					pair_list.emplace_back(to_string((data_column + 1) + i_count));//�y�A���X�g�ɒǉ�
					except_number_list.push_back((data_column + 1) + i_count);//���O���X�g�ɒǉ�
					++pair_count;
				}

				++i_count;
			}
		}
		
			//�y�A����~�ȏ�ł���΃t�@�C���ɒǉ�
		if (pair_count >= 3) {

			for (int j = 0; j < inDataList.at(data_column).size(); ++j)
				result_list.at(result_list_column).at(j) = inDataList.at(data_column).at(j);


				string number = to_string(pair_count);
				//cout << "No." << data_column << "'s Pair: ";
				
				//for (int l=0; l < pair_list.size(); ++l) {
					//string s_pair = to_string(pair_list.at(l));
					//result_list.at(result_list_column).emplace_back(to_string(l));//�����ɓ���̃v���C���[��ǉ�
					//cout << "No." << pair_list.at(l)<<" ";
				//}
			
				//cout << endl;
		
				//inDataList.erase(inDataList.begin() + i);
				it = result_list.at(result_list_column).begin();//
				it = result_list.at(result_list_column).insert(it, to_string(pair_count));
				
				//cout << result_list.at(data_column).size() << endl;
				result_list.at(data_column).resize(11);
				//cout << result_list.at(data_column).size() << endl;

				
				++num_of_pairs;
				++result_list_column;//CSV�t�@�C���̉��s
				
		}

		pair_list.clear();//�y�A���X�g�̃N���A
		//vector<string>().swap(pair_list);
		++data_column;
		i_count = 0;
		pair_count = 0;
	}
	/*cout <<"Pairs:" <<num_of_pairs << endl;

	cout << result_list.size() << endl;*/
	//cout << result_list.at(0).size() << endl;

	result_list.resize(num_of_pairs);

	return result_list;
}
