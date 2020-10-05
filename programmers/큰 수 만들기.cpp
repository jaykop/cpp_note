#include <string>
#include <vector>

using namespace std;

string rec(string str, int K)
{
    if (!K)
    {
        return str;
    }
    
    size_t size = str.length();
    string max;
    for (size_t i = 0 ; i < size; ++i)
    {
        string copy = str;
        copy.erase(copy.begin() + i);
        if (max.empty())
            max = copy;
        else
            max = max > copy ? max : copy;
    }
    
    return rec(max, K - 1);
}

string solution(string number, int k) {
    
    return rec(number, k);
}