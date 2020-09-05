#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<int> food_times, long long k) {

    int i = 0, size = food_times.size();
    map<int, int> next;
    while (k--)
    {
        int last = i;
        while (!food_times[i])
        {
            if (next.find(i) == next.end())
            {
                while (!food_times[i])
                {
                    i = ++i % size;
                    if (i == last)
                        return -1;
                }
                next[last] = i;
            }
            else
                i = next[last];

            if (i == last) 
                return -1;
        }

        food_times[i]--;
        i = ++i % size;
    }

    return (i % size) + 1;
}

int main()
{
    vector<int> v = { 2, 0, 1 };
    solution(v, 2);
    return 0;
}