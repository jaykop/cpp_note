#include <iostream>

using namespace std;
int solution(int n)
{
    int ans = 0;
    while (n)
    {
        int rem = n % 10;
        ans += rem;
        n -= rem;
        n /= 10;
    }
    return ans;
}