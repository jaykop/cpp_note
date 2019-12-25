#pragma once
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {

        //vector<int> toReturn, odds;
        // for (auto i : A){
        //     if (i % 2) odds.push_back(i);
        //     else toReturn.push_back(i);
        // }
        // for (auto j : odds)
        //     toReturn.push_back(j);

        for (int i = 0, j = int(A.size() - 1);
            i < j; ) {

            while (A[i] % 2 == 0) {
                i++;
            }
            while (A[j] % 2 == 1) {
                j--;
            }
            if (i >= j)
                break;
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;

        }
        return A;
    }
};