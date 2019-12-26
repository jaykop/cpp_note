class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        
        // 2N - size of the vector
        int size = int(A.size());
        // N - the single one's appreance
        int n = size/2;
        // N+1 - num of unique ints
        //
        int toReturn = -1;
        
        vector<int> table(n+2, 0);
        // iterate thru the vector
        for (int i : A) {
            
            if (i >= int(table.size()))
                table.resize(i+1, 0);
            
            table[i]++;
            if (table[i] == n)
                toReturn = i;
        }
        
        return toReturn;
    }
};