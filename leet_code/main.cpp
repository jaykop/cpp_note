#include "combinationSum.h"
#include <iostream>

int main() {
		
    //vector<vector<char>> t =
    //{
    //    {'8', '3', '.', '.', '7', '.', '.', '.', '.'},
    //    {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
    //    {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
    //    {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
    //    {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
    //    {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
    //    {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
    //    {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
    //    {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    //};
    //    
    //    //{
    ////    {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
    ////    {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
    ////    {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
    ////    {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
    ////    {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
    ////    {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
    ////    {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
    ////    {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
    ////    {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    ////};

    vector<int> v = { 2,3,6,7 };
    int t = 7;

	Solution a;
	auto ans = a.combinationSum(v, t);

	return 0;}