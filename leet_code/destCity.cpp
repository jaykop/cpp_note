class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        
        map<string, int> record, cadidate;
        for (const auto& p : paths)
        {
            record[p[0]]++;
            record[p[1]]++;
            cadidate[p[1]]++;
            if (record[p[0]] == 2) {
                record.erase(p[0]);
                cadidate.erase(p[0]);
            }
            if (record[p[1]] == 2) {
                record.erase(p[1]);
                cadidate.erase(p[1]);
            }
        }
        
        return cadidate.begin()->first;
    }
};

// best answer
// class Solution {
// public:
    // string destCity(vector<vector<string>>& paths) {
        
        // unordered_map<string, string> record;
        // for (const auto& p : paths)
        // {
            // record[p[0]] = p[1];
        // }
        // for (const auto& p : paths)
        // {
            // if (record.find(p[1]) == record.end())
                // return p[1];
        // }
        
        // return "";
    // }
// };