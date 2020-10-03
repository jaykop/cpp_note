#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, 
    int weight, 
    vector<int> truck_weights) {

    queue<int> q;
    int i = 0, sum = 0, time = 0, 
        size = truck_weights.size(), left = size;

    while (left)
    {
        if (q.size() == bridge_length && q.front())
        {
            left--;
            sum -= q.front();
            q.pop();
        }

        while (!q.empty() && !q.front())
            q.pop();

        if (q.size() < bridge_length)
        {
            if (i < size && sum + truck_weights[i] <= weight)
            {
                q.push(truck_weights[i]);
                sum += q.back();
                ++i;
            }
            else
                q.push(0);
        } 

        ++time;
    }

    return time;
}

int main()
{
    vector<int> v = { 10 };
    solution(100, 100, v);

    return 0;
}