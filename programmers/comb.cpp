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
	vector<int> v1 = { 4, 1, 5, 2, 3, },
		v2 = { 1, 3, 7, 9, 5, },
		v3, ans;

	int size = -1;
	scanf("%d", size);

	v1.resize(size);
	for (int i = 0; i < size; i++)
		scanf("%d", v1[i]);

	scanf("%d", size);

	v2.resize(size);
	for (int i = 0; i < size; i++)
		scanf("%d", v2[i]);

	for (auto i : v1)
	{
		if (v3.size() <= i)
			v3.resize(i + 1);

		v3[i] = 1;
	}

	for (auto i : v2)
		if (v3.size() <= i || !v3[i])
			ans.push_back(0);
		else
			ans.push_back(1);


	//vector<int> v = {1, 2, 3, 4};
	//return_subset(v);
	//auto i = return_digit(60466175, 36);
	return 0;
}