#pragma once
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {

        // get the lowest numbers from each row
        int m = matrix.size(), n = matrix[0].size();
        vector<int> luckyNums, 
            lowests(n, numeric_limits<int>::max()),
            largests(m, -numeric_limits<int>::max());
        set<int> low, lar;
        for (int c = 0; c < n; c++)
        {
            int lowest = numeric_limits<int>::max();
            int lowest_r = -1;
            for (int r = 0; r < m; r++)
            {
                if (matrix[r][c] < lowest) {
                    lowest = matrix[r][c];
                    lowest_r = r;
                }
            }

            if (largests[c] > lowest) {
                largests[c] = lowest;
                lar.insert(lowest);
            }

            if (lowests[lowest_r] < lowest)
            {
                lowests[lowest_r] = lowest;
                low.insert(lowest);
            }
        }

        for (auto i : low)
            if (lar.find(i) != lar.end())
                luckyNums.emplace_back(i);

        return luckyNums;
    }
};

//class Solution {
//public:
//    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
//
//        // get the lowest numbers from each row
//        vector<int> lowests, luckyNums;
//        int m = matrix.size(), n = matrix[0].size();
//
//        for (int c1 = 0; c1 < n; c1++)
//        {
//            int largest = -numeric_limits<int>::max();
//            int largest_r = -1;
//            for (int r = 0; r < m; r++)
//            {
//                if (matrix[r][c1] > largest) {
//                    largest = matrix[r][c1];
//                    largest_r = r;
//                }
//            }
//
//            bool add = true;
//            for (int c2 = 0; c2 < n; c2++)
//            {
//                if (largest > matrix[largest_r][c2])
//                {
//                    add = false;
//                    break;
//                }
//            }
//
//            if (add)
//                luckyNums.emplace_back(largest);
//        }
//
//        return luckyNums;
//    }
//};