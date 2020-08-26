#pragma once
#include <string>
#include <iostream>
#include <filesystem>
#include <vector>
#include <filesystem>
#include <array>
#include <list>
#include <fstream>

using namespace std;

//����̃v���O�����ɕK�v�Ǝv����@�\���W��
//����K�����N���X�Ɋ֐����ڐA�\��
class DataTool
{
public:
	DataTool();
	~DataTool();


	const vector<string> Split(string& inLine, char inDeleteWord);//�Ώۂ̕����񂩂�w�肵���������Ƃɕ���

	const list<string> SplitToList(string& inLine, char inDeleteWord);//�Ώۂ̕����񂩂�w�肵���������Ƃɕ���
	const list<int> SplitNumber(string& inLine, char inDeleteWord);//�Ώۂ̕����񂩂�w�肵���������Ƃɕ���


	//�t�@�C���̕ۑ����resource�t�H���_�����ɂ���֐�
	inline string const SetFilePath(string& inFileName) { return "resource/"+inFileName;};

	bool GetFileNames(string inFolderPath, vector<string>& inFileName);
	const bool IsExitNumber(vector<int>& inVector, int& inNumber);

	const void MakeResultData(vector<vector<string>>& inDataList, string inFileName);

};

