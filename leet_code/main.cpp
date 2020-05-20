#include "countBattleships.h"

int main() {

	vector<vector<char>> v =
	{
		/*{'X', '.'},
		{'.', 'X'}*/
		/*{'X'}*/
		{'X', 'X', 'X'}
		/*{'X', '.', '.', 'X'},
		{'.', '.', '.', 'X'},
		{'.', '.', '.', 'X'}*/
	};

	Solution a;
	auto b = a.countBattleships(v);

	return 0;
}