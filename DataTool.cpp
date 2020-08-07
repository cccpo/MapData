#include "DataTool.h"

DataTool::DataTool() {

}

DataTool::~DataTool() {

}

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