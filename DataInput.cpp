#include "DataInput.h"

DataInput::DataInput() :mVectorDates(10001, vector<int>(10)),ks(10001){
	
}

DataInput::~DataInput() {

}

//CSV�f�[�^�Ǎ��֐�
const vector<vector<int>> DataInput:: LoadCSVData(string& ioFile) {
	string line;
	
	//�t�@�C���p�X�ݒ�
	string file_path = data_tool.SetFilePath(ioFile);
	ifstream input_file(file_path);

	//�C�e���[�^�ݒ�
	vector<vector<int>>::iterator m_vector_iterator = mVectorDates.begin();
	vector<int>::iterator mm_vector_iterator;
	
	//�S�s�ǂݍ���
	while (getline(input_file, line)) {
		mm_vector_iterator = m_vector_iterator->begin();//
		list<int> data_set = data_tool.Split(line, ',');//�Z�����Ƃɕ����Alist<int>�ŏo��
		
		//�f�[�^���i�[
		for (auto it = data_set.begin(); it != data_set.end(); ++it) {
			*mm_vector_iterator = *it;
			//cout << *mm_vector_iterator;
			++mm_vector_iterator;
		}

		//cout << endl;
		++m_vector_iterator;
	


	}
	mVectorDates.erase(mVectorDates.begin());

	return mVectorDates;
}



//���͂����t�@�C���f�[�^����
//vector<int> DataInput::GetFileData(const string& inFileName, vector<string>& ioVectorDatas) {
//	ifstream ifs(inFileName);
//	list<string> player_route,player_id, player_route2;
//	list<int> pls_in;
//
//	if (!ifs)
//	{
//		//cout << "Error"<< endl;
//	}
//
//	string tmp;
//	while (getline(ifs, tmp)) {
//		ioVectorDatas.emplace_back(tmp);
//	}
//
//	/*cout << tmp << endl;*/
//
//	player_id = data_tool.Split(ioVectorDatas[0], ':');//����
//	player_id.erase(player_id.begin());
//	
//	player_route = data_tool.Split(ioVectorDatas[1],':');
//	player_route.erase(player_route.begin());
//
//	player_route = data_tool.Split(player_route[0], '.');
//
//	pls_in=ConvertFileData(player_route);
//
//	return pls_in;
//
//
//
//}

list<int> DataInput::ConvertFileData(vector<string>& ioVectorDatas) {
	string tesu_a;
	list<int> lisya;
	
	for (int i = 0; i < ioVectorDatas.size(); i++) {
		//cout << "PlayerRoutePOS:" << i << endl;
		//cout << ioVectorDatas[i][1]<<"," << ioVectorDatas[i][3] <<endl;
		//cout << "DataSize:" << ioVectorDatas[i].size() << endl;
		
		int test_number2 = ioVectorDatas[i][3] - '0';
		
		lisya.emplace_back(test_number2);
		//cout << test_number << endl;
		//for (int j = 0; j < ioVectorDatas[i].size(); j++) {
		//	//int test_number = ctoi(ioVectorDatas[i][1]);
		//	cout << ioVectorDatas[i][j] << endl;
		//	}
	}
	//cout << mDataList.size() << endl;

	//�f�[�^�����X�g�Ɋi�[����
	for (int i = 0; i < lisya.size(); i++) {
		//tesu_a = to_string(lisya[i]);
		//cout << tesu_a << endl;
	}

	return lisya;
}

vector<string> DataInput::SearchPlayerData(string inPlayerID) {

	//for (int i = 0; i < mVectorDates.size(); i++) {
	//	if (mVectorDates.at(i).at(0) == inPlayerID) {
	//		return mVectorDates.at(i);
	//	}
	//}

}

//�����Ƃ����v���C���[�l�[�������݂��邩����������V�X�e��
bool DataInput::IsExitPlayerID(string inPlayerID) {
	//for (int i = 0; i < mVectorDates.size(); i++) {
	//	if (mVectorDates.at(i).at(0) == inPlayerID) {
	//		cout << "Find" << endl;
	//		return true;
	//	}
	//}

	cout << "Can't find" << inPlayerID << endl;
	return false;

}

void DataInput::Sort() {
	//data_sort.DeleteKeyCategory(mVectorDates);
}
