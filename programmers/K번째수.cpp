#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    
    vector<int> answer;
    for (const auto& v : commands)
    {
        vector<int> new_v(array.begin()+v[0]-1, array.begin()+v[1]);
        sort(new_v.begin(), new_v.end());
        answer.push_back(new_v[v[2]-1]);
    }
        
    return answer;
}