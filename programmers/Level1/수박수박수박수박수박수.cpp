#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string ans;
    if (n > 0)
    {
        for (int i = 0; i < n; ++i)
            if (i % 2)
                ans += "박";
            else
                ans += "수";
    }
    return ans;
}