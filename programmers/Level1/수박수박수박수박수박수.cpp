#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int i = s.length() - 1, end = 0, ans = 0, mul = 1;
    bool neg = false;
    if (s[0] == '-')
    {
        neg = true;
        end = 1;
    }
    else if (s[0] == '+')
        end = 1;
    for (; i >= end; --i)
    {
        ans += (s[i] - '0') * mul;
        mul *= 10;
    }
    if (neg) ans *= -1;
    return ans;
}

int main()
{
    auto i = solution("1234");
    return 0;
}