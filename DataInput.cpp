#include "DataInput.h"

DataInput::DataInput() {
	
}

DataInput::~DataInput() {

}

//int DataInput::GetPlayerRoute() {
//	return mPlayerRoute.size();
//}

void DataInput:: LoadData(vector<string>& ioVectorDatas) {

}

//�o�H�����_�������̂��߂ɍ쐬�A���݂�TestDataMaker�ɒu���Ă���
array<int,10> DataInput::GetPlayerRoute() {
	random_device rnd;
	mt19937 mt(rnd());
	uniform_int_distribution<int> first_number(0, 9);//0�`9�͈̔͂ŗ�������
	uniform_int_distribution<int> second_number(2, 4);//2�`4�͈̔͂ŗ�������


	for (int i = 0; i < 10; ++i) {
		if (i == 0) {
			mData[i] = first_number(mt);
		}else{
			mData[i] = mData[i-1] + second_number(mt) - 3;
		}
	}
	
	return mData;
}

vector<int> DataInput::GetFileData(const string& inFileName, vector<string>& ioVectorDatas) {
	ifstream ifs(inFileName);
	vector<string> player_route,player_id, player_route2;
	vector<int> pls_in;

	if (!ifs)
	{
		cout << "Error"<< endl;
	}

	string tmp;
	while (getline(ifs, tmp)) {

		ioVectorDatas.emplace_back(tmp);
	}

	/*cout << tmp << endl;*/

	player_id = data_tool.Split(ioVectorDatas[0], ':');
	player_id.erase(player_id.begin());
	

	player_route = data_tool.Split(ioVectorDatas[1],':');
	player_route.erase(player_route.begin());

	player_route = data_tool.Split(player_route[0], '.');

	pls_in=ConvertFileData(player_route);

	return pls_in;



}

vector<int> DataInput::ConvertFileData(vector<string>& ioVectorDatas) {
	string tesu_a;
	vector<int> lisya;
	
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
		tesu_a = to_string(lisya[i]);
		cout << tesu_a << endl;
	}

	return lisya;
}

