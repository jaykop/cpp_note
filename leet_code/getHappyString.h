#pragma once
#include <vector>
#include <string>
#include <queue>

using namespace std;

class Solution {
public:
    string getHappyString(int n, int k) {

        int cases = pow(2, n - 1) * 3;
        int count = 0;
        priority_queue<string> pq;

        pq.push("a");
        pq.push("b");
        pq.push("c");

        vector<string> candidates;
        while (count < cases)
        {
            string s = pq.top();
            pq.pop();
            if (s.length() == n) {
                candidates.emplace_back(s);
                count++;
            }
            for (char c = 'a'; c < 'd'; c++)
            {
                if (s.back() != c && s.length() < n)
                {
                    pq.push(s + c);
                }
            }
        }

        return candidates[cases - k - 1];
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