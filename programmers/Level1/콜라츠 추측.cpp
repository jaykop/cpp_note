#include <string>
#include <vector>

using namespace std;
using ull = unsigned long long;
int solution(int num) {
    int ans = 0;
    ull n = static_cast<ull>(num);
    while (n != 1)
    {
        ++ans;
        if (ans == 501)
            return -1;
        
        if (n % 2) n = n * 3 + 1;
        else n /= 2;
    }
    return ans;
}