#include "DataInput.h"

DataInput::DataInput() {
	
}

DataInput::~DataInput() {

}

//int DataInput::GetPlayerRoute() {
//	return mPlayerRoute.size();
//}

//Œo˜Hƒ‰ƒ“ƒ_ƒ€¶¬‚Ì‚½‚ß‚Éì¬AŒ»İ‚ÍTestDataMaker‚É’u‚¢‚Ä‚¢‚é
array<int,10> DataInput::GetPlayerRoute() {
	random_device rnd;
	mt19937 mt(rnd());
	uniform_int_distribution<int> first_number(0, 9);//0`9‚Ì”ÍˆÍ‚Å—””­¶
	uniform_int_distribution<int> second_number(2, 4);//2`4‚Ì”ÍˆÍ‚Å—””­¶


	for (int i = 0; i < 10; ++i) {
		if (i == 0) {
			mData[i] = first_number(mt);
		}else{
			mData[i] = mData[i-1] + second_number(mt) - 3;
		}
	}
	
	return mData;
}

vector<string> DataInput::GetFileData(string inFileName, vector<string>& ioVectorDatas) {
	ifstream ifs(inFileName);

	if (!ifs)
	{
		cout << "Error"<< endl;
	}

	string tmp;
	while (getline(ifs, tmp))
		ioVectorDatas.push_back(tmp);

	return ioVectorDatas;

}

vector<string> AddFileData(vector<string>& ioVectorDatas) {

}

