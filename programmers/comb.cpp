#include <vector>
#include <cmath>
#include <string>

using namespace std;

string return_digit(int n, int k)
{
	int rest = -1;// n% k, div = n / k;

	string ans;

	while (n)
	{
		rest = n % k;
		n = n / k;
		if (rest < 10)
			ans.insert(0, to_string(rest));

		else
		{
			char c = rest + ('A' - 10);
			ans.insert(0, 1, c);
		}
	}

	return ans;
}


vector<vector<int>> return_subset(const vector<int> v)
{
	vector<vector<int>> ans;
	size_t size = v.size();
	size_t end = pow(2, size);

	// 2^n 만큼의 부분집합
	for (int i = 0; i < end; ++i)
	{
		vector<int> subset;

		// binary 값으로 체크하며 부분집합 추가\
		// size는 비트 자리 수
		for (int j = 0; j < size; ++j)
		{
			if (i & (1 << j)) // 1을 j만큼 움직여서 i와의 비트셋을 체크한다
			{
				subset.push_back(v[j]);
			}
		}

		ans.emplace_back(subset);
	}

	return ans;
}

int main()
{
	vector<int> v = {1, 2, 3, 4};
	return_subset(v);
	auto i = return_digit(121, 11);
	return 0;
}