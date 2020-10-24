#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

string change_digit(int n, int k)
{
	string ans;

	while (n)
	{
		int mod = n % k;
		n = n / k;
		ans += to_string(mod);
	}

	return ans;
}

vector<vector<int>> subset(const vector<int>& v)
{
	vector<vector<int>> ans;
	int size = static_cast<int>(v.size());
	int n = pow(2, size);

	// 총 부분집합의 수
	for (int i = 0; i < n; ++i)
	{
		vector<int > subset;

		for (int j = 0; j < size; ++j)
		{
			// 자리수마다 0 1 체크
			if (i & (1 << j))
				subset.push_back(v[j]);
		}

		ans.emplace_back(subset);
	}

	return ans;
}

void lexical_permutation(const vector<int>& v)
{
	
}

bool mobile(const vector<int>& v,
    const vector<int>& d,
    int& largest)
{
    vector<int> mobiles;
    int size = static_cast<int>(v.size());
    for (int i = 0; i < size; ++i)
    {
        if (((d[i] == 1 && i < size - 1)
            || (d[i] == -1 && i > 0))
            && v[i + d[i]] < v[i])
            mobiles.emplace_back(i);
    }

    bool found = !mobiles.empty();

    if (found)
    {
        largest = mobiles[0];
        for (auto i : mobiles)
            if (v[i] > v[largest])
                largest = i;
    }
    return found;
}

vector<vector<int>> permute(vector<int>& nums) {

    vector<vector<int>> res;
    if (nums.empty()) return res;
    sort(nums.begin(), nums.end());
    int size = static_cast<int>(nums.size());
    vector<int> dirs(size, -1);
    int largest = 0;
    res.emplace_back(nums);

    while (mobile(nums, dirs, largest))
    {
        int k = nums[largest];
        int offset = dirs[largest];
        swap(nums[largest], nums[largest + offset]);
        swap(dirs[largest], dirs[largest + offset]);
        
        for (int i = 0; i < size; ++i)
        {
            if (nums[i] > k)
                dirs[i] *= -1;
        }

        res.emplace_back(nums);
    }

    return res;
}

int main()
{
	auto s = change_digit(133, 11);
	vector<int> v = { 5,4,6,2 };
	auto ss = subset(v);
    auto p = permute(v);
	return 0;
}