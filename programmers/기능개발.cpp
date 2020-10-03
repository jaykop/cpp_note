#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {

    int size = speeds.size();
    vector<int> v, ans;
    for (int i = 0; i < size; ++i)
    {
        int n = 1;
        while (progresses[i] + speeds[i] * n < 100)
            n++;
        v.push_back(n);
    }

    int m = v.front();
    int n = 0;
    size = v.size();
    for (auto i : v)
    {
        if (m >= i)
            ++n;
        else
        {
            ans.push_back(n);
            n = 1;
            m = i;
        }
    }

    if (n)
        ans.push_back(n);

    return ans;
}

int main()
{
    vector<int> v1 = { 95, 95, 95, 95/*93, 30, 55*//*95, 90, 99, 99, 80, 99*/ }, v2 = {/*1, 30, 5*//*1, 1, 1, 1, 1, 1*/4,3,2,1 };
    solution(v1, v2);
    return 0;
}