class Solution {
public:
    
    bool selfdivisible(int i) {
        
        const int n = i;
        
        while (i) {
            
            int digit = i % 10;
            if (!digit || n % digit)
                return false;
            i -= digit;
            i /= 10;
        }
        
        return true;
    } 
    
    vector<int> selfDividingNumbers(int left, int right) {
        
        vector<int> output;
        
        for (int i = left ; i <= right ; i++ ){
            
            if (selfdivisible(i))
                output.push_back(i);
        }
        
        return output;
    }
};