class Solution {
public:
    bool isValid(string s) {
        
        if (s.empty()) return true;
        if (s.size() % 2) return false;
        
        stack<char> str;
        for (const auto& c : s)
        {
            if (str.empty())
                str.push(c);
            else
            {
                auto toPop = str.top();
                if (toPop == '(' && c == ')')
                    str.pop();
                else if (toPop == '['&& c == ']')
                    str.pop();
                else if (toPop == '{'&& c == '}')
                    str.pop();
                else
                    str.push(c);
            }
        }
        if (str.empty())
            return true;
        
        return false;
    }
};