#include <cmath>

using namespace std;

long long gcd(long long a, long long b)
{
    long long r;
    while (b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

long long solution(int w,int h) {

    long long answer = static_cast<long long>(w) * static_cast<long long>(h);
    long long d = (static_cast<long long>(w) 
                   + static_cast<long long>(h)
                   - gcd(w, h));
    
    return answer - d;
}