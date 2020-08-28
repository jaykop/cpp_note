#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    
    int sum = 0, y = x;
    while (y)
    {
        int rem = y % 10;
        sum += rem;
        y -= rem;
        y /= 10;   
    }
    if (x % sum) return false;
    return true;
}