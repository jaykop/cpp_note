#include <vector>
#include <map>
#include <set>
#include <tuple>

using namespace std;
using mat = vector<vector<long>>;

void rec(int x, int y,
    int r, int c,
    mat& m, int n, int& count)
{
    if (0 <= x && x < r
        && 0 <= y && y < c
        && n > 0 && m[x][y] == n)
    {
        m[x][y] = -1;
        ++count;
        rec(x + 1, y, r, c, m, n, count);
        rec(x, y + 1, r, c, m, n, count);
        rec(x, y - 1, r, c, m, n, count);
        rec(x - 1, y, r, c, m, n, count);
    }
}

int invade(mat& m,
    int r, int c,
    int& number_of_area)
{
    set<int> s;
    int max = 0;
    for (int x = 0; x < r; ++x)
        for (int y = 0; y < c; ++y)
            if (m[x][y] > 0)
            {
                s.insert(m[x][y]);
                int count = 0;
                rec(x, y, r, c, m, m[x][y], count);
                if (count > max)
                    max = count;
            }
    number_of_area = s.size();
    return max;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    vector < vector<long>> pic;
    for (auto p : picture)
    {
        vector<long> lp;
        for (auto l : p)
            lp.emplace_back(static_cast<long>(l));
        pic.emplace_back(lp);
    }

    max_size_of_one_area = invade(pic, m, n, number_of_area);

    vector<int> answer(2);
    answer[0] = number_of_area + 1;
    answer[1] = max_size_of_one_area;
    return answer;
}

int main()
{
    vector<vector<int>> v =
        {{1, 1, 1, 0}, {1, 2, 2, 0}, {1, 0, 0, 1}, {0, 0, 0, 1}, {0, 0, 0, 3}, {0, 0, 0, 3}};
    
    auto a = solution(6, 4, v);
    
    return 0;
}