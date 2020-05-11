#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {

        vector<int> toReturn(nums.size(), -1);
        map<int, vector<int>> hashMap;

        int j = 0;
        for (const auto& i : nums) {

            if (hashMap.find(i) == hashMap.end()) {
                vector<int> index;
                index.emplace_back(j);
                hashMap.insert({ i, index }); // value, index
            }
            else
                hashMap[i].emplace_back(j);

            j++;

        }

        sort(nums.begin(), nums.end());

        j = 0;
        int offset = 0;
        for (const auto& i : nums) {

            toReturn[hashMap[i].back()] = j;
            hashMap[i].pop_back();

            if (!hashMap[i].empty())
                offset++;

            else {
                j += offset;
                offset = 0;
                j++;
            }
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