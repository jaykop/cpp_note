#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool check(int h, const vector<int>& v)
{
    int count = 0;
    for (auto i : v)
    {
        if (h <= i)
            ++count;
    
        if (count >= h)
            return false;
    }

    return true;
}

int solution(vector<int> citations) {

    sort(citations.begin(), citations.end(), greater<int>());
    int h = citations.front();
    int count = 1;
    while (check(h, citations))
        h--;

    return h;
}

int main()
{
    vector<int> v = { 0, 0, 5, 5, 5, 5, 6, };
    solution(v);
    return 0;
}