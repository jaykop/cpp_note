#include <string>
#include <vector>
#include <map>
#include <tuple>
#include <algorithm>

using namespace std;

bool compare(const tuple<float, int>& a,
    const tuple<float, int>& b)
{
    if (get<0>(a) > get<0>(b)) return true;
    else if (get<0>(a) < get<0>(b)) return false;
    else
    {
        if (get<1>(a) < get<1>(b))
            return true;
        else return false;
    }
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> ans, log;
    map<int, float> table;
    int size = stages.size();
    for (int s = 1; s <= N; ++s)
    {
        for (int i = 0; i < size; ++i)
        {
            if (stages[i] > s)
                table[s]++;
        }
    }

    int last = size;
    vector<tuple<float, int>> tv;
    for (int s = 1; s <= N; ++s)
    {
        int temp = table[s];
        table[s] = (last - table[s]) / last;
        last = temp;
        tv.emplace_back(table[s], s);
    }

    sort(tv.begin(), tv.end(), compare);
    for (const auto& t : tv)
        ans.push_back(get<1>(t));

    return ans;
}

int main()
{
    vector<int> v = { 2, 1, 2, 6, 2, 4, 3, 3 };
    solution(5, v);
    return 0;
}