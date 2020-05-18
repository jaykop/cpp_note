#pragma once
class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {

        int res = 0;
        int size = int(endTime.size());
        for (int i = 0; i < size; i++)
        {
            if (startTime[i] <= queryTime
                && queryTime <= endTime[i])
                res++;
        }

        return res;
    }
};