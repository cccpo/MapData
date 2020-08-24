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
	vector<vector<string>> result_list(10000, vector<string>(10));
	vector<string> pair_list;//�g�ݍ��킹�����������o�H���i�[����
	
	vector<int> except_number_list;
	vector<string>::iterator it;

	int i_count=0;
	int pair_count = 0;//�y�A�����J�E���g����
	int result_list_column=0;//CSV�t�@�C���̉��s�ڂɃf�[�^���J�E���g����̂�������
	int num_of_pairs = 0;//�����l�g�p�����o�H�����J�E���g����

	int data_column = 0;

	//cout << inDataList.size() << endl;
	//cout << inDataList.at(1).size() << endl;

	//cout << result_list.size() << endl;
	//cout << result_list.at(1).size() << endl;

	//�f�[�^�̍s������
	while (data_column < inDataList.size()){
		//���O���X�g�Ɋ܂܂�Ă��Ȃ��ꍇ�������s��
		if (!data_tool.IsExitNumber(except_number_list, data_column)) {
			while ((data_column + 1) + i_count < inDataList.size()) {
				//���v����o�H������Β��o����
				if (inDataList.at(data_column) == inDataList.at((data_column + 1) + i_count)) {
					pair_list.emplace_back(to_string((data_column + 1) + i_count));//�y�A���X�g�ɒǉ�
					except_number_list.emplace_back((data_column + 1) + i_count);//���O���X�g�ɒǉ�
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
				//result_list.at(result_list_column).emplace_back(to_string(pair_count));

				it = result_list.at(result_list_column).begin();//
				it = result_list.at(result_list_column).insert(it, to_string(pair_count));
				
				//cout << result_list.at(data_column).size() << endl;
				//result_list.at(data_column).resize(11);
				//cout << result_list.at(data_column).size() << endl;

				
				++num_of_pairs;
				++result_list_column;//CSV�t�@�C���̉��s
				
		}

		vector<string>().shrink_to_fit();
		++data_column;
		i_count = 0;
		pair_count = 0;
	}
	result_list.resize(num_of_pairs);//�y�A�����̍s���Ƀ��T�C�Y

	return result_list;
}
