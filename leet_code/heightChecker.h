#pragma once
class Solution {
public:
    int heightChecker(vector<int>& heights) {

        auto copied = heights;
        int size = heights.size();
        int count = 0;
        sort(copied.begin(), copied.end());
        for (int i = 0; i < size; i++)
        {
            if (copied[i] != heights[i])
                count++;
        }

        return count;
    }
};