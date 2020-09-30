#include <string>
#include <vector>

using namespace std;

int rec(const vector<int>& v, int sum, int i, const int target)
{
    int ans = 0;
    
    if (i == v.size())
    {
        if (sum == target)
            return ans + 1;
        
        return ans;
    }
    
    ans += rec(v, sum + v[i], i+1, target);
    ans += rec(v, sum - v[i], i+1, target);
    
    return ans;
}

int solution(vector<int> numbers, int target) {
    int answer = rec(numbers, 0, 0, target);
    return answer;
}