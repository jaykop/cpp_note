#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    int ans = 0;
    
    int sq = static_cast<int>(sqrt(n));
    for (int i = 1 ; i <= sq; ++i)
        if (n % i == 0)
        {
            if (n/i == i)
                ans += i;
            else
            {
                ans += n/i;
                ans += i;
            }
        }
    return ans;
}

int main()
{
    solution(6);
    return 0;
}