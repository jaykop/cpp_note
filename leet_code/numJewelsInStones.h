#include <string>
#include <set>
using namespace std;

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        
        int toReturn = 0; // num of jewels in stone
        set<char> jset;

        //
        for (const auto& c : J)
            jset.insert(c);

        for (const auto& s : S) {
            if (jset.find(s) != jset.end())
                toReturn++;
        }
        

        return toReturn;
    }
};