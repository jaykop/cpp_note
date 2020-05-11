#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {

        if (nums.empty())
            return -1;

        int size = int(nums.size());
        if (size == 1) {
        
            if (nums[0] == target)
                return 0;
            else return -1;
        }
            
        bool found = false;
        int start = 0;
        int pivot = size / 2;

        while (pivot != size) {
        
            if (nums[start] < target 
                && target < nums[pivot]) {

                for (int i = start; i <= pivot; i++)
                    if (target == nums[i])
                        return i;
            }

            else {

                start = pivot;
                pivot = pivot * 2;
                if (pivot >= size)
                    pivot = size - 1;
            }
        }

        return -1;
    }
};

//class Solution {
//public:
//
//    // first idea
//    int search(vector<int>& nums, int target) {
//
//        bool found = false;
//        int size = int(nums.size());
//
//        for (int i = 0; i < size; i++) {
//            if (nums[i] > target)
//                break;
//
//            else if (nums[i] == target)
//                return i;
//        }
//
//        for (int i = size - 1; i >= 0; i--) {
//            if (nums[i] < target)
//                break;
//
//            else if (nums[i] == target)
//                return i;
//        }
//
//        return -1;
//
//    }
//};

int main()
{
    vector<int > a =  { 4, 5, 6, 7, 0, 1, 2 };
    Solution sol;
    int b = sol.search(a, 0);

    return 0;
}