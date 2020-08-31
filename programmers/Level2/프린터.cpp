#include <vector>
#include <map>
#include <stack>

using namespace std;

bool added_all(const vector<bool>& v)
{
    for (auto b : v)
        if (!b) return false;
    return true;
}

int solution(vector<int> pt, int location) {

    stack<int> s;
    map<int, int> table;
    size_t size = pt.size(), i = 1, p = 1;
    vector<bool> added(size, false);
    added[0] = true;
    s.push(0);

    while (!added_all(added))
    {
        while (!s.empty() && pt[s.top()] < pt[i]
            && !added[i])
        {
            added[s.top()] = false;
            s.pop();
            p--;
        }

        if (!added[i])
        {
            s.push(i);
            table[i] = p++;
            added[i] = true;
        }
        i = ++i % size;
    }

    return table[location] + 1;
}

int main()
{
    vector<int> v = { 1, 1, 9, 1, 1, 1 };
    auto i = solution(v, 0);
    return 0;
}