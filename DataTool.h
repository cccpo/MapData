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

	//�t�@�C���̕ۑ����resource�t�H���_�����ɂ���֐�
	inline string const SetFilePath(string inFileName) { return "resource/"+inFileName;};

	vector<string> Split(string& inLine, char inDeleteWord);//�Ώۂ̕����񂩂�w�肵���������Ƃɕ���

	bool IsFindVec(vector<int> inVector, int inNumber);
	bool GetFileNames(string folderPath, vector<string>& file_names);

	void MakeResultData(vector<vector<string>> inDataList, string inFileName);

};

