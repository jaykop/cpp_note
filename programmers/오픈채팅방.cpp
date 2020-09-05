#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> record) {
    
    vector<string> ans;
    map<string, string> table;

    // parse
    for (const string& s : record)
    {
        size_t first = s.find_first_of(' ');
        size_t second = s.find_last_of(' ');
        string key = s.substr(first + 1, second - first - 1);
        string newName = s.substr(second + 1, s.size());
        if (s.substr(0, first) == "Change" ||
            s.substr(0, first) == "Enter")
            table[key] = newName;
    }

    for (const string& s : record)
    {
        size_t first = s.find_first_of(' ');
        size_t second = s.find_last_of(' ');
        string key = s.substr(first + 1, second - first - 1);
        string sentence(table[key]+"님이 ");

        if (s.substr(0, first) == "Enter")
        {
            sentence += "들어왔습니다.";
            ans.emplace_back(sentence);
            continue;
        }

        else if (s.substr(0, first) == "Leave")
        {
            sentence += "나갔습니다.";
            ans.emplace_back(sentence);
            continue;
        }

    }
    return ans;
}

int main()
{
    vector<string> a = { "Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan" };
    //b = { "Prodo님이 들어왔습니다.", "Ryan님이 들어왔습니다.", "Prodo님이 나갔습니다.", "Prodo님이 들어왔습니다." };
    solution(a);
    return 0;
}