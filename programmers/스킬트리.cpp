#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int solution(string skill, 
    vector<string> skill_trees) {

    int count = 0;
    int s_size = skill.length();
    map<char, int> s_table;
    for (int i = 0; i < s_size; ++i)
        s_table[skill[i]] = i;

    for (const auto& s : skill_trees)
    {
        int size = s.length();
        string shrink;
        for (int i = 0; i < size; ++i)
        {
            auto found = s_table.find(s[i]);
            if (found != s_table.end())
                shrink += s[i];
        }

        int share_size = std::min(shrink.length(), skill.length());
        bool correct = true;
        for (int i = 0; i < share_size; ++i)
            if (shrink[i] != skill[i])
                correct = false;

        if (correct) count++;

    }

    return count;
}

int main()
{
    string skill = "CBD";
    vector<string> skills = { "BACDE", "CBADF", "AECB", "BDA" };
    
    solution(skill, skills);
    return 0;
}