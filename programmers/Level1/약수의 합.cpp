#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    int ans = 0;
    
    int sq = static_cast<int>(sqrt(n));
    for (int i = 0 ; i < sq; ++i)
        if (i % 2 == 0)
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