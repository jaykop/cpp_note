#pragma once
#include <vector>
#include <string>
#include <queue>

using namespace std;

class Solution {
public:
	string getHappyString(int n, int k) {

		int cases = pow(2, n - 1) * 3;
		vector<string> candidates;
		if (cases < k)
			return "";

		else if (n == 1)
		{
			candidates.emplace_back("a");
			candidates.emplace_back("b");
			candidates.emplace_back("c");

			return candidates[k - 1];
		}

		int count = 0;
		priority_queue<string> pq;

		pq.push("c");
		pq.push("b");
		pq.push("a");

		while (!pq.empty())
		{
			string s = pq.top();
			pq.pop();

			for (char c = 'c'; c >= 'a'; c--) {
				if (s.back() != c && s.length() < n)
				{
					string new_s = s + c;
					if (new_s.length() == n)
						candidates.emplace_back(new_s);
					
					else
						pq.push(new_s);
				}
			}
		}

		return candidates[cases - k];
	}
};


//class Solution {
//public:
//    string getHappyString(int n, int k) {
//
//        int cases = pow(2, n - 1) * 3;
//        if (cases < k)
//            return "";
//
//        int count = 0;
//        priority_queue<string> pq;
//
//        pq.push("a");
//        pq.push("b");
//        pq.push("c");
//
//        vector<string> candidates;
//        while (count < cases)
//        {
//            string s = pq.top();
//            pq.pop();
//            if (s.length() == n) {
//                candidates.emplace_back(s);
//                count++;
//            }
//            for (char c = 'a'; c < 'd'; c++) {
//                if (s.back() != c && s.length() < n)
//                {
//                    pq.push(s + c);
//                }
//            }
//        }
//
//        return candidates[cases - k];
//    }
//};