class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        
        if (arr.size() != target.size())
            return false;
        
        std::sort(arr.begin(), arr.end());
        std::sort(target.begin(), target.end());
        int size = int(arr.size());
        for (int i = 0 ; i < size; ++i)
        {
            if (target[i] != arr[i])
                return false;
        }
        
        return true;
    }
};

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        vector<int> f(1001, 0);
        int count{0};
        for(int i{0}, size{(int)target.size()}; i < size; ++i) {
            
            ++f[target[i]];
            if(f[target[i]] == 0) --count;
            else if(f[target[i]] == 1) ++count;
            
            --f[arr[i]];
            if(f[arr[i]] == 0) --count;
            else if(f[arr[i]] == -1) ++count;
        }
        return count == 0;
    }
};