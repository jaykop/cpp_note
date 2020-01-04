class Solution {
public:
    vector<int> diStringMatch(string S) {
        
        // 
        int from_high = (S.length());
        int from_low = 0;
        
        // vector to return
        // which starts with 0
        vector<int> result;
        
        // iterate the given string
        for (const auto& c : S){
            
            // condition A[i] < A[i+1]
            if (c == 'I')
                result.push_back(from_low++);
            
            // condition A[i] > A[i+1]
            else 
                result.push_back(from_high--);
        }
        
        // the last one does not matter
        // either to add from_high or from_low
        result.push_back(from_high--);
        
        // return the result
        return result;
    }
};