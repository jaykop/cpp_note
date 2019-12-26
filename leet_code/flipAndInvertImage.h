#pragma once
#include <vector>
using namespace std;


class Solution {
public:

    void invert(int& a) {

        if (a) a = 0;
        else a = 1;
    }

    void swap(int& a, int& b) {

        if (a != b) {
            int temp = b;
            b = a;
            a = temp;
        }
    }

    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {

        int a_size = int(A.size());
        int v_size = int(A[0].size());
        for (int i = 0; i <= a_size / 2; i++) {

            int j = a_size - 1 - i;
            // here we reverse the vector,
            for (int i2 = 0; i2 < v_size / 2; i2++) {

                int j2 = v_size - 1 - i2;
                if (i <= j) {
                    swap(A[i][i2], A[i][j2]);

                    if (i != j && i2 < j2)
                        swap(A[j][i2], A[j][j2]);
                }
            }
        }

        for (int i = 0; i < a_size; i++)
            for (int i2 = 0; i2 < v_size; i2++)
                invert(A[i][i2]);

        return A;
    }

};