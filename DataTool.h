#pragma once
#include <string>
#include <iostream>
#include <filesystem>
#include <vector>

using namespace std;

//����̃v���O�����ɕK�v�Ǝv����@�\���W��
//����K�����N���X�Ɋ֐����ڐA�\��
class DataTool
{
public:
	DataTool();
	~DataTool();

	vector<string> Split(string str, char del);

};

