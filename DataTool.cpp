#include "DataTool.h"

DataTool::DataTool() {

}

DataTool::~DataTool() {

}

//‘ÎÛ‚Ì•¶š—ñ‚©‚çw’è‚µ‚½•¶š‚Å•ªŠ„
vector<string> DataTool::Split(string inWord, char inDeleteWord) {
    int first = 0;
    int last = inWord.find_first_of(inDeleteWord);

    vector<string> result;

    while (first < inWord.size()) {
        string subStr(inWord, first, last - first);

        result.emplace_back(subStr);

        first = last + 1;
        last = inWord.find_first_of(inDeleteWord, first);

        if (last == string::npos) {
            last = inWord.size();
        }
    }

    return result;
}

bool DataTool::GetFileNames(std::string folderPath, std::vector<std::string>& file_names)
{
    return true;
}