#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool compare(const pair<int, int>& a, const pair<int, int>& b)
{
    if (a.first == b.first)
        return a.second < b.second;

    return a.first > b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {

    int size = plays.size();
    map<string, int> sum;
    map<string, vector<pair<int, int>>> list;
    for (int i = 0; i < size; ++i)
    {
        sum[genres[i]] += plays[i];
        list[genres[i]].emplace_back(plays[i], i);
    }

    vector<pair<int, string>> sorted;
    for (auto it = sum.begin(); it != sum.end(); ++it)
        sorted.emplace_back(it->second, it->first);

    sort(sorted.begin(), sorted.end(), greater<pair<int, string>>());

    vector<int> answer;

    for (auto it = sorted.begin(); it != sorted.end(); ++it)
    {
        string genre = it->second;
        sort(list[genre].begin(), list[genre].end(), compare);
        answer.push_back(list[genre][0].second);
        if (list[genre].size() > 1)
            answer.push_back(list[genre][1].second);
    }

    return answer;
}

int main()
{
    vector<string> s = { "classic", "classic", "classic", "classic", "pop" };
    vector<int> i = { 500, 150, 800, 800, 2500 };
    solution(s, i);
    return 0;
}