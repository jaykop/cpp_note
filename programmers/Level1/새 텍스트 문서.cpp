#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    
    for (auto c : s)
        if (!('0' <= c && c <= '9'))
            return false;
    size_t len = s.length();
    if (len == 4 || len == 6) return true;
    return false;
}