#include <string>
#include <iostream>
#include <vector>
#include <array>

using namespace std;


class DataInput

{
public:
		DataInput();
		~DataInput();

		inline int GetPlayerID() {};
		//int GetPlayerRoute();

		array<int, 10> GetPlayerRoute();
protected:
	string mPlayerId;//PlayerID
	
	
};

