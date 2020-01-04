class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int peak = 0;
        int size = int(A.size());
        for (int i = 1; i < size; i++)
            if (A[i] > A[peak])
                peak = i;
            
        return peak;
    }
};