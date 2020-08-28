#include <string>
#include <vector>

using namespace std;

double solution(vector<int> arr) {
    double ans = 0;
    for (const auto& d : arr)
        ans += d;
    return ans / static_cast<double>(arr.size());
}