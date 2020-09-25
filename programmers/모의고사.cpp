#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const pair<int, int>& a, const pair<int, int>& b)
{
    if (a.first == b.first)
        return a.second < b.second;

    return a.first > b.first;
}

vector<int> solution(vector<int> answers) {

    int p_size = static_cast<int>(answers.size());
    vector<int> lists = { p_size, p_size, p_size }, mod = { 5, 8, 10 };
    vector<int> answer;
    vector<vector<int>> patterns = {
        {1,2,3,4,5},
        {2,1,2,3,2,4,2,5},
        {3,3,1,1,2,2,4,4,5,5}
    };

    for (int i = 0; i < p_size; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (answers[i] != patterns[j][i % mod[j]])
                --lists[j];
        }
    }
    vector<pair<int, int>> sorted;
    for (int i = 0; i < 3; ++i)
        sorted.emplace_back(lists[i], i);

    sort(sorted.begin(), sorted.end(), compare);
    answer.push_back(sorted.begin()->second + 1);
    int last = sorted.begin()->first;
    for (auto it = sorted.begin() + 1; it != sorted.end() ; ++it)
    {
        if (last == it->first)
            answer.push_back(it->second + 1);
        else
            break;
            
    }
    return answer;
}

int main()
{
    vector<int> v = { 1, 3, 2, 4, 2 };
    solution(v);
    return 0;
}