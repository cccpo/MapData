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
	vector<list<int>> result_list(10000, list<int>(10));
	
	vector<int> pair_list;//�g�ݍ��킹�����������o�H���i�[����

	//�C�e���[�^�ݒ�
	vector<vector<int>>::iterator m_vector_iterator = inDataList.begin();//����
	vector<vector<int>>::iterator m_vector_iterator2nd;


	vector<int>::iterator mm_vector_iterator;
	vector<int>::iterator mm_vector_iterator2nd;
	vector<int>::iterator mm_vector_iterator3rd = (*m_vector_iterator).begin();

	
	list<int> except_number_list;//���O���X�g


	vector<string>::iterator it;

	vector<list<int>>::iterator result_list_iretator = result_list.begin();
	list<int> rresult_list_iretator;

	int i_count=0;
	int pair_count = 0;//�y�A�����J�E���g����
	int result_list_column=0;//CSV�t�@�C���̉��s�ڂɃf�[�^���J�E���g����̂�������
	int num_of_pairs = 0;//�����l�g�p�����o�H�����J�E���g����

	int data_column = 0;

	//cout << inDataList.size() << endl;
	//cout << *mm_vector_iterator3rd << endl;

	//cout << result_list.size() << endl;
	//cout << result_list.at(1).size() << endl;

	int NumOfRoop;
	int AllRoop = 0;
	//�f�[�^�̍s������
	for (m_vector_iterator; m_vector_iterator != inDataList.end(); ++m_vector_iterator) {

		NumOfRoop = 0;

		//���O���X�g�ɓ����Ă��邩���m�F
		if (!data_tool.IsExitNumber(except_number_list, data_column)) {
			//cout << data_column << endl;

			m_vector_iterator2nd = m_vector_iterator+1;
			//���O���X�g�Ɋ܂܂�Ă��Ȃ��ꍇ�������s��
			for (m_vector_iterator2nd; m_vector_iterator2nd != inDataList.end();++m_vector_iterator2nd) {
				
				//���v����o�H������Β��o�A����̃y�A�����J�E���g
				if (*m_vector_iterator == *m_vector_iterator2nd) {
					
					//���v�����l���m�F����
					for (mm_vector_iterator = (*m_vector_iterator2nd).begin(); mm_vector_iterator != (*m_vector_iterator2nd).end();++mm_vector_iterator) {
						//cout << *mm_vector_iterator;
					}
					cout << *mm_vector_iterator2nd << endl;

					pair_list.emplace_back(((data_column + 1) + NumOfRoop));//�y�A���X�g�ɒǉ�
					//cout << "Data_column(" << i_count <<")+NumofRoop"<< NumOfRoop << endl;;
					//except_number_list.emplace_back((data_column + 1) + NumOfRoop);//���O���X�g�ɒǉ�
					++pair_count;
					//cout << "Pair:" << pair_count << endl;;
					//cout << endl;
					++i_count;
				}
				
				++NumOfRoop;
			}

			
			

			//�y�A����~�ȏ�ł���΃t�@�C���ɒǉ�
			if (pair_count >= 3) {

				//for (int j = 0; j < inDataList.at(data_column).size(); ++j)
				//*result_list_iretator = *m_vector_iterator;
				//rresult_list_iretator = (*result_list_iretator).begin();

				//string number = to_string(pair_count);
				cout << "No." << data_column << "'s Pair: ";

				for (int l=0; l < pair_list.size(); ++l) {
					string s_pair = to_string(pair_list.at(l));
					//result_list.at(result_list_column).emplace_back(to_string(l));//�����ɓ���̃v���C���[��ǉ�
					cout << "No." << pair_list.at(l)<<" ";
				}

				cout << endl;

				//inDataList.erase(inDataList.begin() + i);
				//result_list.at(result_list_column).emplace_back(to_string(pair_count));

				//result_list_iretator = result_list_iretator->emplace_front(pair_count);//�C�e���[�^���őO��
				//it = result_list.at(result_list_column).insert(it, to_string(pair_count));//�y�A�̃J�E���g

				//cout << result_list.at(data_column).size() << endl;
				//result_list.at(data_column).resize(11);
				//cout << result_list.at(data_column).size() << endl;

				++result_list_iretator;

			
				++num_of_pairs;
				++result_list_column;//CSV�t�@�C���̉��s

			}

			//vector<string>().shrink_to_fit();

			++data_column;
			i_count = 0;
			pair_count = 0;
			pair_list.clear();
			//cout << "data_column:" << data_column << endl;//���[�v�񐔂̊m�F
			//cout << "NumfOfRoop:" << NumOfRoop << endl;//���[�v�񐔂̊m�F
		}
		
		result_list.resize(num_of_pairs);//�y�A�����̍s���Ƀ��T�C�Y
		AllRoop += NumOfRoop;//AllRoop�ɉ��Z
	}
	cout << AllRoop<<endl;//�S���[�v�񐔂̊m�F
	

	return result_list;
}
