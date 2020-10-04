#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    
    vector<int> v(n, 1);
    
    for (auto i : lost)
        --v[i - 1];
    
    for (auto i : reserve)
        ++v[i - 1];
    
    int ans = 0;
    
    for (int i = 0 ; i < n; ++i)
    {
        if (v[i] >= 1)
        {
            ++ans;
            if (v[i] > 1)
            {
                if (i > 0 && v[i - 1] == 0)
                {
                    ++v[i - 1];
                    ++ans;
                    --v[i];
                }
                else if (i < n - 1 && v[i + 1] == 0)
                {
                    ++v[i + 1];
                    --v[i];
                }
            }
        }
    }
    
    return ans;
}