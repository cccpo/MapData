#include "DataTool.h"

DataTool::DataTool() {

}

DataTool::~DataTool() {

}

//‘ÎÛ‚Ì•¶š—ñ‚©‚çw’è‚µ‚½•¶š‚Å•ªŠ„
vector<string> DataTool::Split(string& inLine, char inDeleteWord) {
    unsigned __int32 first = 0;
    unsigned __int32 last =  inLine.find_first_of(inDeleteWord);
    
    vector<string> result;

    while (first < inLine.size()) {
        string subStr(inLine, first, last - first);

        result.emplace_back(subStr);

        first = last + 1;
        last = inLine.find_first_of(inDeleteWord, first);

        if (last == string::npos) {
            last = inLine.size();
        }
    }

    return result;
}

bool DataTool::GetFileNames(std::string folderPath, std::vector<std::string>& file_names)
{
    return true;
}