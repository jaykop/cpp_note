#include <string>
#include <vector>
#include <cmath>

using namespace std;

bool sq(long long l)
{
    int max = static_cast<int>(sqrt(l));
    for (int i = 1 ; i <= max; ++i)
        if (l / i == i)
            return true;
    return false;
}

long long solution(long long n) {
    long long ans = -1;
    if (n > 0 && sq(n))
    {
        long long l = sqrt(n) + 1;
        ans = l * l;
    }
    return ans;
}