#include <vector>

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {

        vector<vector<int>> toReturn;
        int size = int(groupSizes);
        for (int i = 0; i < size; i++) {

            // check if there is a list to add the element
            bool found = false;
            for (auto &g : toReturn) {

                // if found a list that is collecting i memebers
                // and not satisfied yet
                if (int(g.size()) != groupSizes[i] &&
                    int(g.size()) == groupSizes[g[0]]) {
                    g.push_back(i);
                    found = true;
                    break;
                }
            }
            // if not found the list,
            // create a new list
            if (!found) {

                toReturn.push_back({i});
            }
        }      

        return toReturn;
    }
};