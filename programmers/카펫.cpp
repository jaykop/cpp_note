#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<int> solution(int brown, int yellow) {

    set<int> sans;
    int size = brown + yellow;
    int sum = (brown + 4) / 2;
    for (int i = 1; i < sum; ++i)
        if (i * (sum - i) == size)
        {
            sans.insert(i);
            sans.insert(sum - i);
        }

    vector<int> ans(sans.begin(), sans.end());
    if (ans.size() == 1)
        ans.push_back(ans.back());
    else
        sort(ans.begin(), ans.end(), greater<int>());

    return ans;
}

int main()
{
    solution(8, 1);
    return 0;
}