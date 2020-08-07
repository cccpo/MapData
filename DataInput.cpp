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

//経路ランダム生成のために作成、現在はTestDataMakerに置いている
array<int,10> DataInput::GetPlayerRoute() {
	random_device rnd;
	mt19937 mt(rnd());
	uniform_int_distribution<int> first_number(0, 9);//0〜9の範囲で乱数発生
	uniform_int_distribution<int> second_number(2, 4);//2〜4の範囲で乱数発生


	for (int i = 0; i < 10; ++i) {
		if (i == 0) {
			mData[i] = first_number(mt);
		}else{
			mData[i] = mData[i-1] + second_number(mt) - 3;
		}
	}
	
	return mData;
}

vector<string> DataInput::GetFileData(const string& inFileName, vector<string>& ioVectorDatas) {
	ifstream ifs(inFileName);

	if (!ifs)
	{
		cout << "Error"<< endl;
	}

	string tmp;
	while (getline(ifs, tmp))
		ioVectorDatas.emplace_back(tmp);

	AddFileData(ioVectorDatas);

	return ioVectorDatas;

}

void DataInput::AddFileData(vector<string>& ioVectorDatas) {
	//cout << ioVectorDatas.size() << endl;
	
	gDataList.emplace_back(ioVectorDatas);
	
	for (int i = 0; i < ioVectorDatas.size(); i++)
		for(int j=0;j < 11; j++)
		cout << gDataList[i][j] << endl;
}

