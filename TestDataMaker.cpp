#include "TestDataMaker.h"

#include <fstream>
TestDataMaker::TestDataMaker() {
	GenerateData();
}

TestDataMaker::~TestDataMaker() {
	//delete &mData;
}

void TestDataMaker ::GenerateData() {
	random_device rnd;
	mt19937 mt(rnd());
	uniform_int_distribution<int> type(0, 9);//0`9‚Ì”ÍˆÍ‚Å—””­¶
	uniform_int_distribution<int> second_number(2, 4);//2`4‚Ì”ÍˆÍ‚Å—””­¶
	
	ofstream test_file("Test.txt");

	if (test_file.fail()) {
		/*return */
		cout << "Error:Can't read text" << endl;
	}

	test_file << "PlayerID:ght" << endl;
	test_file << "PlayerCourse:";
	for (int i = 0; i < 10; ++i) {
		if (i == 0) {
			mData[i] = type(mt);
		}else {
			mData[i] = mData[i - 1] + second_number(mt) - 3;

		}

		test_file << mData[i] << ",";
	}
	
	test_file.close();



}