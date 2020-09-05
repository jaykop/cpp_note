#include <string>
#include <vector>

using namespace std;

int solution(vector<int> food_times, long long k) {

    int i = 0, size = food_times.size();
    while (k--)
    {
        int last = i;
        while (!food_times[i])
        {
            i = ++i % size;
            if (i == last) return -1;
        }
        food_times[i]--;
        i = ++i % size;
    }

    return i + 1;
}

int main()
{
    vector<int> v = { 3, 1, 2 };
    solution(v, 5);
    return 0;
}