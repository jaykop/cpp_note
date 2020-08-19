class Solution {
public:
    
    bool rec(const string& s1,
            const string& s2,
            const string& s3,
            size_t i, size_t j, size_t k)
    {

        if (i + j == s3.size()) return true;
        
        return (s1[i] == s3[k] && rec(s1, s2, s3, i+1, j, k+1)) 
            || (s2[j] == s3[k] && rec(s1, s2, s3, i, j+1, k+1));
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        
        if (s1.empty() && s2.empty() && s3.empty())
            return true;
        
        else if ((s1.size() + s2.size()) != s3.size())
            return false;
        
        return rec(s1, s2, s3, 0, 0, 0);
    }
};