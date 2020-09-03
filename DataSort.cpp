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

const vector<list<int>> DataSort::IntDeleteKeyCategory(vector<vector<string>>& inDataList) {
	vector<list<int>> sort_dates;//�f�[�^���i�[����vector
	vector<list<int>>::iterator sort_dates_iretator = sort_dates.begin();
	list<int>::iterator list_iretator;


	//cout << "Dele";
	//sort_dates = inDataList;

	//cout << inDataList.at(0).at(0) << endl;
	
	inDataList.erase(inDataList.begin());//1�s�ڂ̏���

	//cout << inDataList.at(0).at(0) << endl;

	
	 //�v���C���[�l�[�����폜
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

	 //�v���C���[�l�[�����폜
	for (int data_column = 0; data_column < sort_dates.size(); ++data_column) {
		sort_dates.at(data_column).erase(sort_dates.at(data_column).begin());
	}

	return sort_dates;
}

//�f�[�^�̒��o���s��
const vector<list<int>> DataSort::ExtractData(vector<vector<int>>& inDataList) {
	vector<list<int>> result_list(100, list<int>(11));//���ʂ��i�[���郊�X�g
	
	vector<int> pair_list;//�g�ݍ��킹�����������o�H���i�[����

	//�C�e���[�^�ݒ�
	vector<list<int>>::iterator result_list_iretator = result_list.begin();
	list<int>::iterator rresult_list_iretator;
	vector<int>::iterator mm_vector_iterator;
	
	
	vector<int> except_number_list;//���O���X�g


	

	int i_count=0;
	int pair_count = 0;//�y�A�����J�E���g����
	int num_of_pairs = 0;//�����l�g�p�����o�H�����J�E���g����

	int data_column = 0;

	int NumOfRoop;
	int AllRoop = 0;


	//�f�[�^�̍s������
	for (vector<vector<int>>::iterator m_vector_iterator = inDataList.begin(); m_vector_iterator != inDataList.end()-1; ++m_vector_iterator) {

		NumOfRoop = 0;//���[�v�񐔂��J�E���g����
		
		//cout << "[DataColumn:"<<data_column <<"]" <<endl;
	/*	for (auto ex_it = except_number_list.begin(); ex_it != except_number_list.end(); ++ex_it) {
			cout << *ex_it << endl;
		}*/

		//���O���X�g�ɓ����Ă��邩���m�F
		if (!data_tool.IsExitNumber(except_number_list, data_column)) {
			//cout << data_column << endl;

		
			//���O���X�g�Ɋ܂܂�Ă��Ȃ��ꍇ�������s��
			for (vector<vector<int>>::iterator m_vector_iterator2nd = m_vector_iterator + 1; m_vector_iterator2nd != inDataList.end();++m_vector_iterator2nd) {
				
				//���v����o�H������Β��o�A����̃y�A�����J�E���g
				if (*m_vector_iterator == *m_vector_iterator2nd) {
					//cout << "roop_count:" << data_row << endl;
					//���v�����l���m�F����
					for (vector<int>::iterator mm_vector_iterator = (*m_vector_iterator2nd).begin(); mm_vector_iterator != (*m_vector_iterator2nd).end();++mm_vector_iterator) {
						//cout << *mm_vector_iterator;
					}
					
					//cout << data_column + 1 + NumOfRoop << endl;
					
					//cout << "[DataColumn:" << data_column << "]" << (data_column + 1) + NumOfRoop <<endl;
					pair_list.emplace_back(((data_column + 1) + NumOfRoop));//�y�A���X�g�ɒǉ�
					except_number_list.emplace_back((data_column + 1) + NumOfRoop);//���O���X�g�ɒǉ�
					++pair_count;
					
					//cout << endl;

				
				}
				
			
				++NumOfRoop;
			}

			//�y�A����3�ȏ�ł���΃t�@�C���ɒǉ�
			if (pair_count >= 3) {
				rresult_list_iretator = (*result_list_iretator).begin();

				
				//*result_list_iretator = *m_vector_iterator;
				

				//string number = to_string(pair_count);
				//cout << "No." << data_column << "'s Pair: ";

				//for (int l=0; l < pair_list.size(); ++l) {
				//	string s_pair = to_string(pair_list.at(l));
				//	//cout << pair_list.at(l);
				//	//except_number_list.emplace_back(pair_list.at(l));//���O���X�g�ɒǉ�
				//	
				//	
				//	cout << "No." << pair_list.at(l)<<" ";
				//}


				*rresult_list_iretator = pair_count;//�y�A����ǉ�����
				for (mm_vector_iterator = (*m_vector_iterator).begin(); mm_vector_iterator != (*m_vector_iterator).end(); ++mm_vector_iterator) {
					++rresult_list_iretator;
					*rresult_list_iretator = *mm_vector_iterator;
				/*	cout << *mm_vector_iterator;*/
					
				}

				//cout << endl;

				
			
				++num_of_pairs;
				++result_list_iretator;


			

		
		/*	cout << except_number_list.size() << endl;
			for (int i = 0; i < except_number_list.size(); ++i) {
				cout << "exceptNum:" << except_number_list.at(i) << endl;
			}*/

			}
			//vector<string>().shrink_to_fit();

			
		}

		++data_column;
		i_count = 0;

		cout << "NumfOfRoop:" << data_column << endl;//���[�v�񐔂̊m�F
		pair_count = 0;
		pair_list.clear();

		
		AllRoop += NumOfRoop;//AllRoop�ɉ��Z
	}
	result_list.resize(num_of_pairs);//�y�A�����̍s���Ƀ��T�C�Y
	//cout << except_number_list.size() << endl;
	//cout << AllRoop<<endl;//�S���[�v�񐔂̊m�F

	return result_list;
}
