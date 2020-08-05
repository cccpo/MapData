#include "DataInput.h"

DataInput::DataInput() {
	
}

DataInput::~DataInput() {

}

//int DataInput::GetPlayerRoute() {
//	return mPlayerRoute.size();
//}

array<int,10> DataInput::GetPlayerRoute() {
	random_device rnd;
	mt19937 mt(rnd());
	uniform_int_distribution<int> type(0, 9);//0`9‚Ì”ÍˆÍ‚Å—””­¶


	for (int i = 0; i < 10; ++i) {
		mData[i] = type(mt);
	}
	
	return mData;
}