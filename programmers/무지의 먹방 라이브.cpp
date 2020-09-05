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
                i = ++i % size;
            
            else
                i = next[i];

            if (i == last) 
                return -1;

            if (food_times[i])
            {
                next[last] = i;
                break;
            }
        }

        food_times[i]--;
        i = ++i % size;
    }

    return (i % size) + 1;
}

int main()
{
    vector<int> v = { 3, 1, 0, 0, 0, 2 };
    solution(v, 5);
    return 0;
}