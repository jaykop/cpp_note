#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {

    int size = static_cast<int>(times.size());
    sort(times.begin(), times.end());

    if (n <= size)
        return times[n - 1];

    auto v = times;
    sort(v.begin(), v.end());

    while (n)
    {
        for (int i = 1; i < size; ++i)
        {
            int res = v[i - 1] + times[i - 1];
            if (res >= v[i])
            {
                v[i - 1] = res;
                break;
            }
        }
        --n;
        sort(v.begin(), v.end());
    }

    long long answer = 0;
    return answer;
}

int main()
{
    int n = 6;
    vector<int> v = { 7, 10 };
    solution(n, v);
    return 0;
}