#pragma once
#include <string>
#include <iostream>
#include <filesystem>
#include <vector>

using namespace std;

//今回のプログラムに必要と思われる機能を集約
//今後適したクラスに関数を移植予定
class DataTool
{
public:
	DataTool();
	~DataTool();

	vector<string> split(string str, char del);

};

