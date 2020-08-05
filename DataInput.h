#include <string>
#include <iostream>
#include <vector>
#include <array>
#include <random>

using namespace std;


class DataInput

{
public:
		DataInput();
		~DataInput();

		void  LoadData();

		inline int GetPlayerID() {};
		//int GetPlayerRoute();

		array<int, 10> GetPlayerRoute();
protected:

	string mPlayerId;//PlayerID
	array<int, 10> mData{ 1,2,3,4,5,6,7,8,9,10 };
	
};

