class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        
        int max = 8, count = 0;
        if ((king[0] + king[1] == 0) 
            || (king[0] + king[1] == 14))
            max = 3;
        else if (king[0] == 0 || king[0] == 7
           || king[1] == 0 || king[1] == 7)
            max = 5;
        
        // get potential positions
        vector<bool> check(8, false);
        vector<vector<int>> pos;
        for (int i = 0; i < 8; i++)
        {
            int l = king[0] - i;
            int r = king[0] + i;
            int u = king[1] - i;
            int d = king[1] + i;
            
            if (!check[0] && 0 <= u)
            {
                vector<int> v = {king[0], u};
                auto found = find(queens.begin(), queens.end(), v);
                if (found != queens.end())
                {
                    count++;
                    pos.push_back(v);
                    check[0] = true;
                }
            }
            if (!check[1] && d < 8)
            {
                vector<int> v = {king[0], d};
                auto found = find(queens.begin(), queens.end(), v);
                if (found != queens.end())
                {
                    count++;
                    pos.push_back(v);
                    check[1] = true;
                }
            }
            if (!check[2] && 0 <= l)
            {
                vector<int> v = {l, king[1]};
                auto found = find(queens.begin(), queens.end(), v);
                if (found != queens.end())
                {
                    count++;
                    pos.push_back(v);
                    check[2] = true;
                }
            }
            if (!check[3] && 0 <= r)
            {
                vector<int> v = {r, king[1]};
                auto found = find(queens.begin(), queens.end(), v);
                if (found != queens.end())
                {
                    count++;
                    pos.push_back(v);
                    check[3] = true;
                }
            }
            if (!check[4] && 0 <= l && 0 <= u)
            {
                vector<int> v = {l, u};
                auto found = find(queens.begin(), queens.end(), v);
                if (found != queens.end())
                {
                    count++;
                    pos.push_back(v);
                    check[4] = true;
                }
            }
            if (!check[5] && 0 <= l && d < 8)
            {
                vector<int> v = {l, d};
                auto found = find(queens.begin(), queens.end(), v);
                if (found != queens.end())
                {
                    count++;
                    pos.push_back(v);
                    check[5] = true;
                }
            }
            if (!check[6] && 0 <= r && 0 <= u)
            {
                vector<int> v = {r, u};
                auto found = find(queens.begin(), queens.end(), v);
                if (found != queens.end())
                {
                    count++;
                    pos.push_back(v);
                    check[6] = true;
                }
            }
            if (!check[7] && 0 <= r && d < 8)
            {
                vector<int> v = {r, d};
                auto found = find(queens.begin(), queens.end(), v);
                if (found != queens.end())
                {
                    count++;
                    pos.push_back(v);
                    check[7] = true;
                }
            }
            
            if (count == max)
                break;
        }
                    
        return pos;
    }
};