#include <iostream>
#include <array>

#include "DataSort.h"
#include "DataInput.h"

using namespace std;

int main() {
	DataInput data_input;
	
	/*cout << "Test Case" << endl;*/
	array<int,10> player_route=data_input.GetPlayerRoute();
	
	for (int i = 0; i < 10; i++) {
		cout << player_route[i]<<",";
	}


	return 0;
}