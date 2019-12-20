#include <string>
using namespace std;

class Solution {
public:
    int balancedStringSplit(string s) {


        // count as many as possible
        int balances = 0;
        int count_r = 0, count_l = 0;
        char last_c = '\0';

        for (const auto& c : s) {

            if (c == 'R'){

                count_r++;
            }

            else if (c == 'L') {

                count_l++;
            }

            // increase the balanace
            // when l == s and both are not zero
            if (count_l && count_r) {

                if ((count_l == count_r)
                    /*&& (last_c != c)*/) {
                    count_l = 0;
                    count_r = 0;
                    balances++;
                }
            }

            // update last 
            last_c = c;
        }

        // return total num of balances
        return balances;
    }
};