#include <string>
#include <vector>

using namespace std;

void rec(vector<vector<int>>& map, int start, int end, int& sum, const int n)
{
    if (map[start][end] == 0)
    {
        sum += 1;

        map[start][end] = -1;
        map[end][start] = -1;
    }

    else if (map[start][end] == 1)
    {
        map[start][end] = -1;
        map[end][start] = -1;

        for (int i = 0; i < n; ++i)
        {
            if (map[end][i] != -1 && i != end)
                rec(map, end, i, sum, n);
        }
    }
}

int solution(int n, vector<vector<int>> c) {

    int ans = 0;

    for (int i = 0; i < n; ++i)
    {
        if (c[0][i] != -1)
            rec(c, 0, i, ans, n);
    }

    return ans;
}

int main()
{
    vector<vector<int>> v = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    };

    solution(3, v);

    return 0;
}