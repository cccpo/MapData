#include "Data.h"

Data::Data() :mVectorDates(10001, vector<string>(11)) {

}

Data::~Data() {

}

const void Data::GenerateTestData(string& inFileName) {
	cout << "Make Test Data" << endl;

	test_data_maker.GenerateTestDataCSV(inFileName, 10000);

	cout << "Success" << endl;
}

const void Data::LoadTestData(string& inFileName) {
	cout << "Load Test Data" << endl;

	mVectorDates = data_input.LoadCSVData(inFileName);


	cout << "Success" << endl;
}