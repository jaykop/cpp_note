class Solution {
public:
    vector<string> letterCombinations(string digits) {
        
        if (digits.empty()) 
            return vector<string>();
        
        unordered_map<char, vector<char>> table;
        vector<vector<char>> elements;
        for (int key = '2', i = 0; key <= '9'; key++ )
        {
            table[key].push_back('a' + i);
            table[key].push_back('a' + i + 1);
            table[key].push_back('a' + i + 2);
            if (key == '7' || key == '9')
            {
                table[key].push_back('a' + i + 3);
                i++;
            }
            i += 3;
        }
        
        deque<string> dq; 
        dq.push_back("");
        ;
        for (auto i : digits)
        {
            int size = dq.size();
            for (auto j : table[i])
            {
                for (int k = 0; k < size; k++)
                {
                    string s = dq[k] + j;
                    dq.push_back(s);
                }
            }
            for (int k = 0; k < size; k++)
                dq.pop_front();
        }
        
        vector<string> res(dq.begin(), dq.end());
        return res;
    }
};