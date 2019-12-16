#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        
        // 
        const auto& begin = s.begin();
        const auto& last = s.end() - 1;

        string toReturn;

        // edge case
        if (s.empty() || s.length() == 1)
            return s;

        else if (s.length() == 2) {

            if (*begin == *last)
                return s;
            toReturn += *begin;
            return toReturn;
        }

        // this loop changes the range of substring to check
        // until decreased last reaches the begin
        auto decreased_last = last;
        for ( ; begin != decreased_last; decreased_last--) {

            // this loop moves the ragne of substing
            // until new_last reaches the end
            auto new_start = begin;
            auto new_last = decreased_last;
            for ( ; new_last != s.end(); new_start++,  new_last++) {

                auto from_start = new_start;
                auto from_last = new_last;

                //toReturn = s.substr(new_start, from_last);
                //string substr_start, substr_last;

                // compare both chars are same no not
                // this part really checkes it the string is palindrom or not
                while (*from_last == *from_start) {

                    // for debug
                    auto a = *from_start;
                    auto b = *from_last;
                    int ds = distance(new_start, from_start);
                    int dl = distance(from_last, new_last);
                    int subtotal = int(distance(new_start, new_last)+1);

                    if (from_start == from_last || (ds + dl) == subtotal) {

                        while (from_start != new_last)
                            toReturn += *from_start++;
                        toReturn += *new_last;
                        return toReturn;
                    }

                    toReturn += *from_start;

                    from_start++;
                    from_last--;
                }

                // didnt meet the condition,
                // re-init the string
                toReturn.clear();
            }

        }
 
        // else case
        toReturn += *s.begin();
        return toReturn;
    }
};