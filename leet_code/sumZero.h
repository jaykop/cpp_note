class Solution {
public:
    vector<int> sumZero(int n) {
        
        vector<int> list;
        // case1: n = 0
        if (!n) list.push_back(0);
        // case2: n = 2k-1
        else if (n % 2) {
            n -= 1;
            n /= 2;
            for (int i = n; i > 0; i--){
                list.push_back(-i);
                list.push_back(i);
            }
            list.push_back(0);
        }
        // case3: n = 2k
        else {
            n /= 2;
            for (int i = n; i > 0; i--){
                list.push_back(-i);
                list.push_back(i);
            }
        }
        
        return list;
    }
};