class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        
        multimap<int, int> table;
        vector<int> res;
        int size_r = mat.size();
        int size_c = mat[0].size();
        for (int i = 0 ; i < size_r; i++)
        {
            int count = 0;
            for (int j = 0; j < size_c; j++)
            {
                if (!mat[i][j])
                    break;
                count++;
            }
            table.insert({count, i});
        }
        
        int i = 0;
        for (auto it = table.begin(); 
             it != table.end() && i < k ; 
             i++, it++)
            res.push_back(it->second);
        
        return res;
    }
};

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        
        vector<pair<int, int>> sorted;
        vector<int> res;
        int size_r = mat.size();
        int size_c = mat[0].size();
        for (int i = 0 ; i < size_r; i++)
        {
            int count = 0;
            for (int j = 0; j < size_c; j++)
            {
                if (!mat[i][j])
                    break;
                count++;
            }
            pair<int, int> p(count, i);
            sorted.push_back(p);
        }
        
        sort(sorted.begin(), sorted.end());
        for (int i = 0; i < k ; i++)
            res.push_back(sorted[i].second);
        
        return res;
    }
};