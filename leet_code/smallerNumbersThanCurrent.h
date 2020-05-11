#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {

        vector<int> toReturn(nums.size(), -1);
        map<int, int> hashMap;

        int j = 0;
        for (const auto& i : nums) {

            if (hashMap.find(i) == hashMap.end()) 
                hashMap.insert({ i, j }); // value, index
            j++;
        }

        sort(nums.begin(), nums.end());

        j = 0;
        for (const auto& i : nums) {

            toReturn[hashMap[i]] = j;
            j++;
        }

        return toReturn;
    }
};

// vector<int> toReturn;
// vector<int> copy(nums);
// sort(copy.begin(), copy.end());
// for (const auto& i : nums)
// {
//     auto it = find(copy.begin(), copy.end(), i);
//     toReturn.emplace_back(distance(copy.begin(), it));
// }
        
// return toReturn;