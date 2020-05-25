#pragma once
#include <vector>
#include <algorithm>
using namespace std;

// my work
class Solution {
public:
    int maxArea(vector<int>& height) {

        int size = height.size();
        int floor = size - 1;
        int max = -1;
        for (auto i : height)
        {
            if (max < i)
                max = i;
        }

        int most = 0;

        while (most < max * floor)
        {
            for (int front = 0, back = floor;
                back < size; front++, back++)
            {
                int water = (back - front) * min(height[back], height[front]);
                if (most < water)
                    most = water;
            }
            floor--;
        }

        return most;
    }
};

// best solution found
class Solution {
public:
    int maxArea(vector<int>& height) {
        int water = 0;
        int i = 0, j = height.size() - 1;
        while (i < j) {
            int h = min(height[i], height[j]);
            water = max(water, (j - i) * h);
            while (height[i] <= h && i < j) i++;
            while (height[j] <= h && i < j) j--;
        }
        return water;
    }
};