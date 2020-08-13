#pragma once
#include <string>
#include <iostream>
#include <filesystem>
#include <vector>
#include <filesystem>

using namespace std;

//今回のプログラムに必要と思われる機能を集約
//今後適したクラスに関数を移植予定
class DataTool
{
public:
	DataTool();
	~DataTool();

	inline string const SetFilePath(string inFileName) { return "resource/"+inFileName;};

	vector<string> Split (string& inLine, char inDeleteWord);//対象の文字列から指定した文字で分割
	bool GetFileNames(std::string folderPath, std::vector<std::string>& file_names);

};

