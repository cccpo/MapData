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

	vector<string> Split(string str, char del);
	bool GetFileNames(std::string folderPath, std::vector<std::string>& file_names);

};

