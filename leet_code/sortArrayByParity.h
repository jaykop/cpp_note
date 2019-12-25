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
        int size = int(A.size());
        for (int i = 0, j = size - 1;
            i < j; ) {

            while (A[i] % 2 == 0) {
                i++;
                if (i == size) break;
            }
            while (A[j] % 2 == 1) {
                j--;
                if (j == 0) break;
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