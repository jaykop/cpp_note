#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {

    int answer = 0;

    vector<queue<int>> newboard;
    int size1 = board.size();
    int size2 = board[0].size();
    for (int i = 0; i < size2; ++i)
    {
        queue<int> q;
        for (int j = 0; j < size1; ++j)
        {
            if (board[j][i])
                q.push(board[j][i]);
        }
        newboard.emplace_back(q);
    }

    vector<int> v;
    for (auto i : moves)
    {
        if (!newboard[i - 1].empty())
        {
            if (!v.empty() &&
                v.back() == newboard[i - 1].front())
            {
                newboard[i - 1].pop();
                v.pop_back();
                answer += 2;
            }
            else
            {
                v.push_back(newboard[i - 1].front());
                newboard[i - 1].pop();
            }
        }
    }

    return answer;
}

int main()
{
    vector<vector<int>> board =
        {
            {0, 0, 0, 0, 0}, 
            {0, 0, 1, 0, 3}, 
            {0, 2, 5, 0, 1}, 
            {4, 2, 4, 4, 2}, 
            {3, 5, 1, 3, 1}
    };

    vector<int> moves =
        {1, 5, 3, 5, 1, 2, 1, 4};
    solution(board, moves);
    return 0;
}