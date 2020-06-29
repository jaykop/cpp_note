#include "exist.h"
#include <iostream>

int main() {

	Solution a;
	vector<vector<char>> v = { 
		  {'A','B','C','E'} ,
		  {'S','F','C','S'},
		  {'A','D','E','E'}
	};
	string s = "ABCB";

	auto i = a.exist(v, s);

	return 0;
}