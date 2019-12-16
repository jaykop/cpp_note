
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // assume that both vectors are already sorted, and not empty

       // create a merged vector
        std::vector<int> merged, wating_list;

        // get size of both vectors
        int s1 = (int)nums1.size();
        int s2 = (int)nums2.size();
        int i = 0, j = 0;
        
        for (; i < s1 && j < s2;) {

            if (nums1[i] > nums2[j]){
                merged.push_back(nums2[j++]);
            }

            else {
                merged.push_back(nums1[i++]);
            }
        }

        while (s1 > i) {

                merged.push_back(nums1[i++]);
        }

        while (s2 > j) {
            
                merged.push_back(nums2[j++]);
        }

        // then eventually we get merged list
        if (merged.size() % 2) {

            return merged[merged.size() / 2];
        }
        else {

            int med1 = (merged.size() / 2);
            int med2 = med1 - 1;
            return (merged[med1] + merged[med2]) / 2.0;
        }
    }
};