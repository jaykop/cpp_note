#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string given = "ab", ans;
    if (n > 0)
    {
        if (n == 1) 
            ans += given[0];
        else if (n == 2) 
            return given;
        for (int i = 0 ; i < n ; ++i)
            ans += given[i % 2];
    }
    return ans;
}

int main()
{
    auto s = solution(3);
    return 0;
}