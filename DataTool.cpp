#include "DataTool.h"

DataTool::DataTool() {

}

DataTool::~DataTool() {

}

//対象の文字列から指定した文字ごとに分割し、y座標の値を出力する
const list<int> DataTool::Split(string& inLine, char inDeleteWord) {
    unsigned __int32 line_first = 0;
    unsigned __int32 line_last =  inLine.find_first_of(inDeleteWord);
    
    list<int> result;
    list<int>::iterator result_iterator = result.begin();

  

    while (line_first < inLine.size()) {
        string subStr(inLine, line_first, line_last - line_first);
        //cout << subStr[3] << endl;//y軸の数値を取得
        
        //内部表現が数値であるためにできる手法
        //二桁である場合は別の方法でなければならない
        result.emplace_back(subStr[3] - '0');

        line_first = line_last + 1;
        line_last = inLine.find_first_of(inDeleteWord, line_first);

        if (line_last == string::npos) {
            line_last = inLine.size();
        }
    }

    //プレイヤーネーム削除
    for (auto it = result.begin(); it != result.end(); ++it) {
        if (result.begin() == it) {
            it = result.erase(it);
        } 
        
       // cout << *it << endl;

    }

    result.resize(10);

    return result;
}

//対象の文字列から指定した文字ごとに分割
const list<string> DataTool::SplitToList(string& inLine, char inDeleteWord) {
    unsigned __int32 line_first = 0;
    unsigned __int32 line_last = inLine.find_first_of(inDeleteWord);

    list<string> result;

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

//対象の文字列から指定した文字ごとに分割
const list<int> DataTool::SplitNumber(string& inLine, char inDeleteWord) {
    unsigned __int32 line_first = 0;
    unsigned __int32 line_last = inLine.find_first_of(inDeleteWord);

    int num_line=0;
    list<int> result;

   // cout << "ls";

    while (line_first < inLine.size()) {
        string subStr(inLine, line_first, line_last - line_first);
        num_line = stoi(subStr);


        result.emplace_back(num_line);

        line_first = line_last + 1;
        line_last = inLine.find_first_of(inDeleteWord, line_first);

        if (line_last == string::npos)
            line_last = inLine.size();
        
    }

    return result;
}


bool DataTool::GetFileNames(string inFolderPath, vector<string>& inFileName)
{
    return true;
}

const bool DataTool::IsExitNumber(vector<int>& inVector, int& inNumber) {
    chrono::high_resolution_clock::time_point start, end;
    //start = chrono::high_resolution_clock::now();//計測開始

   // const int X = inNumber;

    //auto x = [](int i) {return i = inNumber; };
    //cout << "ExitNumber:" << inNumber << endl;
    //start = chrono::high_resolution_clock::now();//計測開始
    auto itr = find(inVector.begin(), inVector.end(), inNumber);
    //end = chrono::high_resolution_clock::now();//計測終了
    //double time = static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0);
    //cout << "[Find]Time:" << time << endl;
    //
    //cout << "ExitNumber:" << inNumber << endl;
    //start = chrono::high_resolution_clock::now();//計測開始
    //auto itt = binary_search(inVector.begin(), inVector.end(), inNumber);
    //end = chrono::high_resolution_clock::now();//計測終了
    //time = static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0);
    //cout << "[binary_search]Time:" << time << endl;
  

    size_t index = distance(inVector.begin(), itr);
   
    //cout << inNumber << ":";
    if (index != inVector.size()) {
        //cout << "ExitNumber:" << inNumber << endl;
        //end = chrono::high_resolution_clock::now();//計測終了
        //double time = static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0);
        //cout << "[DataTool::IsExitNumber]Time:" << time << endl;
        return true;
    }else {
        //end = chrono::high_resolution_clock::now();//計測終了
        //double time = static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0);
        //cout << "[DataTool::IsExitNumber]time:" << time << endl;
        return false;
    }
    /*return itt;*/
}

//抽出結果をCSVデータに出力する
const void DataTool::MakeResultData(vector<list<int>>& inDataList, string inFileName) {
    string file_path = SetFilePath(inFileName);

    ofstream data_sort_result(file_path);//出力形式
    data_sort_result << "Num" << "," << "Cource" << endl;

    int counter;
    for (vector<list<int>>::iterator m_vector_iterator = inDataList.begin();
        m_vector_iterator!= inDataList.end(); ++m_vector_iterator) {
        
        for (list<int>::iterator mm_vector_iterator = (*m_vector_iterator).begin();
            mm_vector_iterator != (*m_vector_iterator).end(); ++mm_vector_iterator) {
            counter = 0;

            if (mm_vector_iterator == (*m_vector_iterator).begin()) {
                data_sort_result << *mm_vector_iterator << ",";
            }

            //cout << *mm_vector_iterator;
            data_sort_result <<"{" <<counter <<"." <<*mm_vector_iterator << "},";
            
            ++counter;
        }

        data_sort_result << endl;

    }
    data_sort_result.close();
}

//ToDO
const void DataTool::MakeResultDataInt(vector<list<int>>& inDataList, string inFileName) {
    string file_path = SetFilePath(inFileName);

    ofstream data_sort_result(file_path);//出力形式
    data_sort_result << "Num" << "," << "Cource" << endl;

    for (int number = 0; number < inDataList.size(); number++) {
        //for (int column_number = 0; column_number < inDataList.at(number).size(); ++column_number) {
        //    if (!inDataList.at(number).at(column_number).empty() && inDataList.at(number).at(column_number) == inDataList.at(number).back()) {
        //        data_sort_result << inDataList.at(number).at(column_number);
        //    }
        //    else {
        //        data_sort_result << inDataList.at(number).at(column_number) << ",";
        //    }
        //}

        //data_sort_result << endl;

    }


    data_sort_result.close();
}
