#pragma once
#include <string>
#include <iostream>
#include <filesystem>
#include <vector>
#include <filesystem>
#include <array>
#include <fstream>

using namespace std;

//����̃v���O�����ɕK�v�Ǝv����@�\���W��
//����K�����N���X�Ɋ֐����ڐA�\��
class DataTool
{
public:
	DataTool();
	~DataTool();

	inline string const SetFilePath(string inFileName) { return "resource/"+inFileName;};

	bool IsFindVec(vector<int> inVector, int inNumber);
	vector<string> Split (string& inLine, char inDeleteWord);//�Ώۂ̕����񂩂�w�肵���������Ƃɕ���
	bool GetFileNames(string folderPath, vector<string>& file_names);

	void MakeResultData(vector<vector<string>> inDataList, string inFileName);

};

