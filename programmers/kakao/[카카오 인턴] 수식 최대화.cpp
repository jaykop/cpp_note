#include <string>
#include <vector>

using namespace std;

long long output(const char* o, long long a, long long b)
{
    switch (*o)
    {
    case '*': return a * b;
    case '+': return a + b;
    case '-': return a - b;
    }
}

long long solution(string exp) {
    vector<string> v;
    size_t size = exp.length();
    size_t start = -1, end = -1;
    for (size_t i = 0; i < size; ++i)
    {
        if ('0' <= exp[i] && exp[i] <= '9')
        {
            if (start == -1)
                start = i;
        }
        else
        {
            v.emplace_back(exp.substr(start, i - start));
            string o; 
            o += exp[i];
            v.emplace_back(o);
            start = -1;
        }
    }
    if (start != -1)
        v.emplace_back(exp.substr(start, size + 1 - start));
    

    vector<vector<string>> orders =
    {
        {"*", "+", "-"},
        {"*", "-", "+"},
        {"+", "-", "*"},
        {"+", "*", "-"},
        {"-", "+", "*"},
        {"-", "*", "+"}
    };

    long long ans = -1;

    for (const auto& c : orders)
    {
        auto copy = v;
        for (const auto& s : c)
        {
            for (int i = 0; i < copy.size();)
            {
                if (copy[i] == s)
                {
                    copy[i - 1] = to_string(output(copy[i].c_str(), stoll(copy[i - 1]), stoll(copy[i + 1])));
                    copy.erase(copy.begin() + i);
                    copy.erase(copy.begin() + i);
                }
                else
                    ++i;
            }
        }

        long long absMax = abs(stoll(copy[0]));
        if (ans < absMax)
            ans = absMax;
    }

    return ans;
}