#include <string>
#include <vector>

using namespace std;

void qsort(int l, int r, string& s)
{
    int i = l, j = r;
    int mid = (l + r) / 2;
    while (i <= j)
    {
        char si = 65 < s[i] && s[i] <= 90 ? s[i] + 32 : s[i];
        char sj = 65 < s[j] && s[j] <= 90 ? s[j] + 32 : s[j];
        char smid = 65 < s[mid] && s[mid] <= 90 ? s[mid] + 32 : s[mid];

        while (si < smid)
        {
            ++i;
            si = 65 < s[i] && s[i] < 90 ? s[i] + 32 : s[i];
        }
        while (smid < sj)
        {
            --j;
            sj = 65 < s[j] && s[j] < 90 ? s[j] + 32 : s[j];
        }

        if (i <= j) swap(s[i++], s[j--]);

    }

    if (i < r) qsort(i, r, s);
    if (l < j) qsort(l, j, s);
}

string solution(string s) {
           
    qsort(0, s.length() - 1, s);

    return s;
}

int main()
{
    solution("Zbcdefg");

    return 0;
}