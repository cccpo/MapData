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