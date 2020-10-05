#include <string>
#include <vector>

using namespace std;

string rec(const string& str, int K)
{
    if (!K)
        return str;

    size_t size = str.length();
    string max;
    for (size_t i = 0; i < size; ++i)
    {
        string copy = str;
        char c = copy[i];
        copy.erase(copy.begin() + i);
        if (max.empty() || max <= copy)
            max = copy;
        else
            break;
    }

    return rec(max, K - 1);
}

string solution(string number, int k) {

    auto begin = *number.begin();
    for (auto i : number)
        if (i != begin)
            return rec(number, k);

    return number.substr(0, number.length() - k);
}