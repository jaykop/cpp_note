#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string ans;
    size_t len = s.length(), mid = len / 2;
    if (len % 2 )
    {
        ans += s[mid];
    }
    else
    {
        ans += s[mid - 1];
        ans += s[mid];
    }
    return ans;
}