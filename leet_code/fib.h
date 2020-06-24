#pragma once

using namespace std;
#include <vector>

// memoization
class Solution {
public:

    vector<int> table;

    int mem(int n)
    {
        if (table[n] == -1)
            table[n] = mem(n - 1) + mem(n - 2);

        return table[n];
    }

    int fib(int N) {

        if (N < 2) return N;

        table.resize(N + 1, -1);
        int a = table.size();
        table[0] = 0;
        table[1] = 1;

        return mem(N);
    }
};

//class Solution {
//public:
//        
//    int fib(int N) {
//        
//        int n[2] = { 0, 1 };
//        if (N < 2) return n[N];
//        
//        int sum = -1;
//        for (int i = 2; i <= N; ++i)
//        {
//            sum = n[1] + n[0];
//            n[0] = n[1];
//            n[1] = sum;
//        }
//        
//        return sum;
//    }
//};