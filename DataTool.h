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
	inline string const SetFilePath(string& inFileName) { return "resource/"+inFileName;};

	const vector<string> Split(string& inLine, char inDeleteWord);//�Ώۂ̕����񂩂�w�肵���������Ƃɕ���

	const bool IsExitNumber(vector<int>& inVector, int& inNumber);
	bool GetFileNames(string inFolderPath, vector<string>& inFileName);

	const void MakeResultData(vector<vector<string>>& inDataList, string inFileName);

};

