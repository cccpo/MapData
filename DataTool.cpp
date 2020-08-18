#include "DataTool.h"

DataTool::DataTool() {

}

DataTool::~DataTool() {

}

//‘ÎÛ‚Ì•¶š—ñ‚©‚çw’è‚µ‚½•¶š‚²‚Æ‚É•ªŠ„
vector<string> DataTool::Split(string& inLine, char inDeleteWord) {
    unsigned __int32 line_first = 0;
    unsigned __int32 line_last =  inLine.find_first_of(inDeleteWord);
    
    vector<string> result;

    while (line_first < inLine.size()) {
        string subStr(inLine, line_first, line_last - line_first);

        result.emplace_back(subStr);

        line_first = line_last + 1;
        line_last = inLine.find_first_of(inDeleteWord, line_first);

        if (line_last == string::npos) {
            line_last = inLine.size();
        }
    }

    return result;
}

bool DataTool::GetFileNames(string folderPath, vector<string>& file_names)
{
    return true;
}

void DataTool::MakeResultData(vector<vector<string>> inDataList,string inFileName) {
    string file_path = SetFilePath(inFileName);

    ofstream data_sort_result(file_path);//o—ÍŒ`®
    data_sort_result << "Num" << "," << "Cource" << endl;

	for (int number = 0; number < inDataList.size(); number++) {
		//string test_number = to_string(number);

		//test_csv_file << "Player" << number << ",";


		for (int column_number = 0; column_number < inDataList.at(number).size(); ++column_number) {
				if (!inDataList.at(number).at(column_number).empty()&& inDataList.at(number).at(column_number) ==inDataList.at(number).back()) {
					data_sort_result << inDataList.at(number).at(column_number);
				}else {
					data_sort_result << inDataList.at(number).at(column_number) <<",";
				}

		}

        data_sort_result << endl;

	}


    data_sort_result.close();
}

bool DataTool::IsFindVec(vector<int> inVector, int inNumber) {
    auto itr = find(inVector.begin(), inVector.end(), inNumber);
    size_t index = distance(inVector.begin(), itr);
   
    if (index != inVector.size()) {
        return true;
    }else {
        return false;
    }
}