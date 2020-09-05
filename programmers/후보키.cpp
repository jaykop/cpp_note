#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

int solution(vector<vector<string>> m) {

    int count = 0;
    vector<map<string, int>> table;
    int size1 = m.size();
    int size2 = m[0].size();

    for (int i = 0; i < size2; ++i)
    {
        int id = 0;
        map<string, int> t;
        for (int j = 0; j < size1; ++j)
        {
            t[m[j][i]] = id++;
        }
        table.emplace_back(t);
    }

    for (auto it = table.begin();
        it != table.end(); )
    {
        if (it->size() == size1)
        {
            it = table.erase(it);
            count++;
        }
        else ++it;
    }

    return count;
}

int main()
{

    vector<vector<string>> v 
        = { {"100", "ryan", "music", "2"}, 
            {"200", "apeach", "math", "2"}, 
            {"300", "tube", "computer", "3"}, 
            {"400", "con", "computer", "4"}, 
            {"500", "muzi", "music", "3"}, 
            {"600", "apeach", "music", "2"} };

    solution(v);
    return 0;
}