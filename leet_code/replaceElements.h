class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        
        // get the last element
        int last = arr.back();
        int size = int(arr.size());
        
        // replace the last element
        arr[size - 1] = -1;
        
        // iterate thru from back to front
        for (int i = size - 2; i >= 0; i--) {
            
            // sava the val before update
            int before = arr[i];
            
            // assign the last val anyway
            arr[i] = last;
            
            if (before > last)
                last = before;
        }
        
        return arr;
    }
};