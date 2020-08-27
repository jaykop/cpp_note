class Solution {
public:
    bool isPalindrome(string s) {
        
        vector<char> chars;
        for (const auto& c : s)
        {
            if ('a' <= c && c <= 'z')
                chars.push_back(c - 32);
            else if ('A' <= c && c <= 'Z')
                chars.push_back(c);
        }
        
        size_t size = chars.size();
        size_t mid =  size % 2 ? size / 2 : size / 2 - 1;
        for (size_t i = 0; i < size; ++i)
            cout << chars[i] << " ";
            //if (chars[i] == chars[size - i - 1])
            //    return false;
        
        return true;
    }
};