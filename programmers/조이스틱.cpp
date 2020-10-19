#include <string>
#include <vector>

using namespace std;

int solution(string name) {

    int size = static_cast<int>(name.length());
    int ans = 0;
    string s(size, 'A');

    for (int i = 0; i < size; ++i)
    {
        int diff = abs(s[i] - name[i]);
        if (diff > 12)
            diff = 26 - diff;
        ans += diff + 1;
    }

    return ans;
}

int main()
{

    auto i = solution("JAZ");
    return 0;
}