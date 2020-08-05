#include "TestDataMaker.h"

#include <fstream>
TestDataMaker::TestDataMaker(){
	//GenerateData();
}

TestDataMaker::~TestDataMaker() {
	
}

void TestDataMaker::GeneratePlayerID(char* inPlayerID, const int inLength) {

}

//ƒf[ƒ^‚Ìƒ‰ƒ“ƒ_ƒ€¶¬
const void TestDataMaker ::GenerateData() {
	random_device rnd;
	mt19937 mt(rnd());
	uniform_int_distribution<int> type(0, 9);//0`9‚Ì”ÍˆÍ‚Å—””­¶
	uniform_int_distribution<int> second_number(2, 4);//2`4‚Ì”ÍˆÍ‚Å—””­¶
	uniform_int_distribution<int> third_number(0, 1);//2`4‚Ì”ÍˆÍ‚Å—””­¶
	
	ofstream test_file("Test1.log");

	if (test_file.fail()) {
		/*return */
		cout << "Error:Can't read text" << endl;
	}
	
	test_file << "PlayerID:ghf" <<endl;

	test_file << "PlayerCourse:";
	for (int i = 0; i < mDataSize; ++i) {
		if (i == 0) {
			mData[i] = type(mt);
		}else {
			if (mData[i-1] == 0) {
				mData[i] = mData[i - 1] + third_number(mt);
			}else if (mData[i-1] == 9) {
				mData[i] = mData[i - 1] - third_number(mt);
			}else
			mData[i] = mData[i - 1] + second_number(mt) - 3;

		}

		test_file << "{"<< i<< ","<<mData[i] << "}";
	}
	
	test_file.close();



}