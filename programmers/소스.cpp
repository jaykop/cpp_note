#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {

    if (clothes.empty()) return 0;

    map<string, int> table;

    for (const auto& v : clothes)
        table[v[1]]++;

    int mul = 1;
    for (auto it = table.begin(); it != table.end(); ++it)
    {
        mul *= (it->second + 1);
    }
    return mul - 1;

}

int main()
{
    vector<string> v = { "119", "97674223", "1195524421" };
    solution(v);
}