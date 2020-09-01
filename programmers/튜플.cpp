#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string s) {

    int max = 0;
    vector<int> v;
    map<int, int> table;
    string number;
    for (auto c : s)
    {
        if ('0' <= c && c <= '9')
            number += c;
        
        else
        {
            if (!number.empty())
            {
                auto key = stoi(number);
                table[key]++;
                if (table[key] > max)
                    max = table[key];
                number.clear();
            }
        }
    }

    while (!table.empty())
    {
        bool removed = false;
        for (auto it = table.begin();
            it != table.end(); ++it)
        {
            if (it->second == max)
            {
                v.push_back(it->first);
                table.erase(it);
                removed = true;
                break;
            }
        }
        if (!removed) --max;
    }
    
    return v;
}

int main()
{
    solution("{{2},{2,1},{2,1,3},{2,1,3,4}}");
    return 0;
}