#pragma once
#include <string>
#include <iostream>
#include <filesystem>
#include <vector>
#include <filesystem>
#include <array>
#include <fstream>

using namespace std;

//今回のプログラムに必要と思われる機能を集約
//今後適したクラスに関数を移植予定
class DataTool
{
public:
	DataTool();
	~DataTool();

	//ファイルの保存先をresourceフォルダ直下にする関数
	inline string const SetFilePath(string& inFileName) { return "resource/"+inFileName;};

	const vector<string> Split(string& inLine, char inDeleteWord);//対象の文字列から指定した文字ごとに分割

	const bool IsExitNumber(vector<int>& inVector, int& inNumber);
	bool GetFileNames(string inFolderPath, vector<string>& inFileName);

	const void MakeResultData(vector<vector<string>>& inDataList, string inFileName);

};

