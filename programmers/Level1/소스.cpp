#include <string>
#include <vector>

using namespace std;

bool character(char c)
{
    if ((65 <= c && c <= 90) || (97 <= c && c <= 122)) 
        return true;
    return false;
}

void qsort(int l, int r, string& s)
{
    int i = l, j = r;
    int mid = (l + r) / 2;

    while (i <= j)
    {
        while (s[i] < s[mid])
            ++i;

        while (s[mid] < s[j])
            --j;

        if (i <= j)
        {
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }

    if (i < r) qsort(i, r, s);
    if (l < j) qsort(l, j, s);
}

string solution(string s) {
           
    string new_s;
    for (auto& c : s)
        if (character(c)) new_s += c;
        
    qsort(0, new_s.length() - 1, new_s);

    for (int i = 0; i < s.length(); ++i)
        if (character(s[i]))
        {
            s[i] = new_s.back();
            new_s.pop_back();
        }
    return s;
}

int main()
{
    solution("absd1f");

    return 0;
}