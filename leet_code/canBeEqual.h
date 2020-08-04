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