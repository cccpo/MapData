#include "DataSort.h"

DataSort::DataSort():mSortVectorDates(10001, vector<string>(11)) {

}

DataSort::~DataSort() {

}

vector<vector<string>> DataSort::NumOfSame(vector<vector<string>> inKSA) {
	mSortVectorDates = inKSA;

	mSortVectorDates.erase(mSortVectorDates.begin());//1�s�ڂ̏������悂�v�f�̍폜
	

	 //cout << mSortVectorDates.at(0).at(0);

	 //�v���C���[�l�[�����폜
	for(int  data_column = 0; data_column < mSortVectorDates.size(); data_column++){
		mSortVectorDates.at(data_column).erase(mSortVectorDates.at(data_column).begin());
	}

	for (int data_column = 0; data_column < mSortVectorDates.size(); data_column++) {
		for (int data_row = 0; data_row < mSortVectorDates.at(data_column).size(); data_row++) {
			//cout << mSortVectorDates.at(data_column).at(data_row);
		}
	//cout << endl;
	}

	cout << mSortVectorDates.size() << endl;
	cout << mSortVectorDates.at(0).size() << endl;

	return mSortVectorDates;
}
