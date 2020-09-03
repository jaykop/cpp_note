#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

int solution(vector<string> user_id, vector<string> banned_id) {

    int ans = 1;
    set<set<string>> v;
    for (const auto& s : banned_id)
    {
        map<char, size_t> table;
        for (size_t i = 0; i < s.size(); ++i)
            if (s[i] != '*')
                table[s[i]] = i;

        set<string> vs;
        for (const auto& id : user_id)
        {
            bool same = true;
            if (s.size() == id.size())
            {
                for (auto c : table)
                {
                    if (id[c.second] != c.first)
                    {
                        same = false;
                        break;
                    }
                }

                if (same)
                    vs.insert(id);
            }
        }
        v.insert(vs);
    }

    return ans;
}

int main()
{
    vector<string>
        v1 = { "frodo", "fradi", "crodo", "abc123", "frodoc" },//{ "frodo", "fradi", "crodo", "abc123", "frodoc" },// { "frodo", "fradi", "crodo", "abc123", "frodoc" },
        v2 = { "fr*d*", "*rodo", "******", "******"};//{ "*rodo", "*rodo", "******" };// {"fr*d*", "abc1**"};

    solution(v1, v2);
    return 0;
}