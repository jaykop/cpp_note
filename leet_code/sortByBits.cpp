class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        
        // unordered_map <int, int> table; // index count
        vector<pair<int, int>> pairs;
        vector<int> res;
        for (int i =0; i < arr.size(); i++)
        {
            int count = 0;
            int n = arr[i];
            if (arr[i]) {
                // check num of 1 bits
                while (arr[i] > 0)
                {
                    if (1 == (arr[i] & 1)) count++;
                    arr[i] >>= 1;
                }
            }
            pair<int, int> p(count, n);
            pairs.emplace_back(p);
        }
        sort(pairs.begin(), pairs.end());
        for (auto r : pairs)
            res.emplace_back(r.second);
        
        return res;
    }
};