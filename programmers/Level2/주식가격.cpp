#include <string>
#include <vector>
#include <map>
#include <stack>
#include <queue>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> ans;
    for (int i = 0; i < prices.size() - 1; ++i)
    {
        int count = 0;
        bool added = false;
        for (int j = i + 1; j < prices.size(); ++j)
        {
            if (prices[j] < prices[i])
            {
                ans.push_back(j - i);
                added = true;
                break;
            }
            count++;
        }
        if (!added)
            ans.push_back(prices.size() - 1 - i);
    }
    ans.push_back(0);
    return ans;
}

int main()
{
    vector<int> v = { 1, 2, 3, 2, 3 };
    solution(v);
    return 0;
}