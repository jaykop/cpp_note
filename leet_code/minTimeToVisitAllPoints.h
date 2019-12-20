#pragma once
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {

        vector<int> current = points[0];
        int total_moves = 0;
        // iterate thru the every point
        for (auto p = points.begin()+1; // starts from second
            p != points.end(); p ++) {
            
            int h = ((*p)[0] - current[0]);
            if (h < 0) h = -h;
            int v = ((*p)[1] - current[1]);
            if (v < 0) v = -v;
            //// min == diagonal moves
            //int min = v < h ? v : h;

            total_moves += v > h ? v : h/*v + h - min*/;
            current = *p;
        }

        return total_moves;
    }
};