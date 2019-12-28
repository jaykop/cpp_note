#pragma once
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> sortedSquares(vector<int>& A) {

		for (auto& i : A) {
			i *= i;
		}

		sort(A.begin(), A.end());

		return A;
		;
	}
};

class Solution {
public:
    
    void swap(int& a, int& b){
        int temp = a;
        a = b;
        b = temp;
    }
    
    vector<int> sortedSquares(vector<int>& A) {
        
		int i = 0, j = A.size() - 1;
		vector<int> toReturn;
		while (i <= j) {

			int a = A[i] * A[i];
			int b = A[j] * A[j];

			if (a > b) {
				toReturn.push_back(a);
				i++;
			} else if (a < b) {
				toReturn.push_back(b);
				j--;
			} else {
				toReturn.push_back(a);
				i++;
			}
		}
		reverse(toReturn.begin(), toReturn.end());
		return toReturn;
    }
};