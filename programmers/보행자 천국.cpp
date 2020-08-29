#include <vector>

using namespace std;

int MOD = 20170805;
int c = 0;

int rec(int m, int n,
    int x, int y, bool from_left,
    const vector<vector<int>>& map)
{
    if (x > m || y > n || map[x][y] == 1) return 0;

    else if (x == m && y == n)
        return 1;

    else
    {
        if (map[x][y] == 2 && (x || y))
        {
            if (from_left)
                return rec(m, n, x, y + 1, true, map); // right
            else
                return rec(m, n, x + 1, y, false, map); // down

        }
        else
        {
            return rec(m, n, x, y + 1, true, map) // right
                + rec(m, n, x + 1, y, false, map); // down
        }
    }
}

int solution(int m, int n, vector<vector<int>> map) {
    
    rec(m-1, n-1, 0, 0, false, map);

    return c % 20170805;
}

int main()
{
    vector<vector<int>> v = 
        {
            {0, 2, 0, 0, 0, 2}, 
            {0, 0, 2, 0, 1, 0}, 
            {1, 0, 0, 2, 2, 0}
        };

    solution(3, 6, v);

    return 0;
}