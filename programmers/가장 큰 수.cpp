#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(const string& a, const string& b)
{
    return a + b > b + a;

    /*if (a.length() == b.length())
    {
        if (a == b)
            return a.length() > b.length();
    }

    if (a.length() >= b.length())
    {
        size_t greater = a.length();
        size_t less = b.length();

        for (size_t i = 0, j = 0; i < greater; ++i, ++j)
        {
            if (j >= less) j = less - 1;

            if (a[i] > b[j])
                return true;
            else if (a[i] == b[j])
                continue;
            else if (a[i] < b[j])
                return false;
        }

        if (a.back() == b.back())
            return a.length() < b.length();
    }

    else if (a.length() < b.length())
    {
        size_t greater = b.length();
        size_t less = a.length();

        for (size_t i = 0, j = 0; i < greater; ++i, ++j)
        {
            if (j >= less) j = less - 1;

            if (b[i] > a[j])
                return false;
            else if (b[i] == a[j])
                continue;
            else if (b[i] < a[j])
                return true;
        }

        if (a.back() == b.back())
            return a.length() < b.length();
    }

    return a.length() > b.length();*/
}

string solution(vector<int> numbers) {

    vector<string> str;

    for (auto i : numbers)
        str.emplace_back(to_string(i));
    sort(str.begin(), str.end(), compare);

    string ans;
    for (const auto& s : str)
        ans += s;

    int i = 0;
    for (; i < ans.length(); ++i)
    {
        if (ans[i] != '0')
            break;
    }

    if (i > 0)
        ans = ans.substr(i - 1, ans.length() - 1);

    return ans;
}

int main()
{
    vector<int> v = { 40, 403 };
    solution(v);
    return 0;
}