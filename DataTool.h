#pragma once
#include <string>
#include <iostream>
#include <filesystem>
#include <vector>
#include <filesystem>

using namespace std;

//����̃v���O�����ɕK�v�Ǝv����@�\���W��
//����K�����N���X�Ɋ֐����ڐA�\��
class DataTool
{
public:
	DataTool();
	~DataTool();

	inline string const SetFilePath(string inFileName) { return "resource/"+inFileName;};

	vector<string> Split (string& inLine, char inDeleteWord);//�Ώۂ̕����񂩂�w�肵�������ŕ���
	bool GetFileNames(std::string folderPath, std::vector<std::string>& file_names);

};

