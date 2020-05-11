#include <functional>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {

        int size = int(satisfaction.size());
        sort(satisfaction.begin(), satisfaction.end());

        int toReturn = 0;
        for (int list = 1; list <= size; list++) {

            int sum = 0;
            for (int i = 1; i <= list; i++) {
                sum += (list - i + 1 )* satisfaction[size - i];
            }

            if (sum > toReturn) 
                toReturn = sum;
            
        }

        return toReturn;
    }
};