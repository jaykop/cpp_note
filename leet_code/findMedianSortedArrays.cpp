
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // assume that both vectors are already sorted, and not empty

       // create a merged vector
        std::vector<int> merged, wating_list;

        // get size of both vectors
        int s1 = (int)nums1.size();
        int s2 = (int)nums2.size();

        // get iterations
        int loop_end = s1 < s2 ? s1 : s2;
        int i = 0;
        for (; i < loop_end; i++) {

            // need to consider!
            // 1. pending values -> need to save in the waring list
            // 2. index issue
            int a = nums1[i];
            int b = nums2[i];

            // case when there is pending numbers
            if (!wating_list.empty()) {

                int c = wating_list.back();
                wating_list.pop_back();

                merged.push_back(min(min(a, b), c)); // add smallest to the list
                
                int largest = max(max(a, b), c);

                while (!wating_list.empty() && 
                    largest > wating_list.back()) {

                    merged.push_back(wating_list.back());
                    wating_list.pop_back();
                }

                wating_list.push_back(largest); // add max to the pending list

                // add middle to the pending list too
                // Checking for b
                if ((a <= b && b <= c) || (c <= b && b <= a)) wating_list.push_back(b);

                // Checking for a
                else if ((b <= a && a <= c) || (c <= a && a <= b)) wating_list.push_back(a);

                else wating_list.push_back(c);

            }

            // 
            else {
                merged.push_back(min(a, b));
                wating_list.push_back(max(a, b));
            }
        }

        int rest_loop = s1 > s2 ? s1 : s2;
        std::vector<int>& rests = nums1.size() > nums2.size() ? nums1 : nums2;
        for (; i < rest_loop; i++) {

            // need to consider!
           // 1. pending values -> need to save in the waring list
           // 2. index issue
            int a = rests[i];

            // case when there is pending numbers
            if (!wating_list.empty()) {

                int b = wating_list.back();
                wating_list.pop_back();
                int smallest = min(a, b);

                while (!wating_list.empty() && 
                    smallest > wating_list.back()) {

                    merged.push_back(wating_list.back());
                    wating_list.pop_back();
                }

                merged.push_back(smallest); // add smallest to the list

                wating_list.push_back(max(a, b)); // add max to the pending list

            }

            // 
            else
                merged.push_back(a);
        }

        // consume the numbers in the wating list
        while (!wating_list.empty()) {

            merged.push_back(wating_list.back());
            wating_list.pop_back();
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