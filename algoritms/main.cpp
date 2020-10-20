#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <numeric>
#include <set>
#include <cmath>
#include <iostream>

using namespace std;

bool prime(int k)
{
	if (k == 2)
		return true;

	else if (k % 2 == 0) 
		return false;

	else
	{
		for (int i = 3; i < k; i += 2)
			if (k % i == 0) 
				return false;

		return true;
	}
}

int main()
{
	int n;
	scanf_s("%d", &n);
	// scanf("%d", &n);

	vector<int> v(n + 1, 0), p;
	int init = 0;
	for (auto& i : v)
		i = init++;

	int range = sqrt(n);

	for (int i = 2; i <= range; ++i)
	{
		if (v[i] == -1) continue;
		else if (prime(i))
		{
			int cnt = i;
			while (1)
			{
				cnt += i;
				if (cnt > n) break;
				v[cnt] = -1;
			}
		}
		else
			v[i] = -1;
	}

	for (auto i : v)
		if (i >= 2) p.push_back(i);

	int s = 0, e = 0, count = 0,
		interval = 0, p_size = static_cast<int>(p.size());
	
	while (1)
	{
		if (interval > n)
		{
			interval -= p[s];
			++s;
		}

		else if (e >= p_size)
			break;

		else // inteval <= n
		{
			interval += p[e];
			++e;
		}

		if (interval == n)
			++count;
	}

	cout << count;

	return 0;
}

//int two_pointer(const vector<int> v, const int target);
//
//int main()
//{
//	int size, target, count = 0;
//	scanf_s("%d", &size);
//	scanf_s("%d", &target);
//	vector<int> v(size, 0);
//	for (int i = 0; i < size; ++i)
//		scanf_s("%d", &v[i]);
//
//	cout << two_pointer(v, target);
//
//	/*for (int i = 0; i < size - 1; ++i)
//	{
//		for (int j = i; j < size; ++j)
//		{
//			int sum = accumulate(v.begin() + i, v.begin() + j, *(v.begin() + i));
//			if (target == sum)
//				count++;
//		}
//	}
//
//	cout << count;*/
//	return 0;
//}
//
//using namespace std;
//
//// 메모이제이션
//int cut_rod_aux(const vector<int>& p, 
//	vector<int>& v, int l)
//{
//	// 양의 값이면 리턴
//	if (v[l] >= 0) 
//		return v[l];
//	
//	// 디폴트
//	int res;
//	if (l == 0) 
//		res = 0;
//	else 
//	{
//		res = INT_MIN;
//		// 이전 메모에서 가장 큰 값 검색
//		for (int i = 1; i <= l; ++i)
//			res = max(res, p[i] + cut_rod_aux(p, v, l - i));
//	}
//
//	// 값 메모
//	v[l] = res;
//	return res;
//}
//
//int cut_rod(const vector<int>& p, int l)
//{
//	// 테이블 초기화 (INT_MIN == 알수없음)
//	vector<int> v(l + 1, INT_MIN);
//	return cut_rod_aux(p, v, l);
//}
//
//int bottom_up_cut_rod(const vector<int>& p, int l)
//{
//	vector<int> v(l + 1, INT_MIN);
//	v[0] = 0;
//	for (int i = 1; i <= l; ++i)
//	{
//		int res = INT_MIN;
//		for (int j = 1; j <= i; ++j)
//			res = max(res, v[i - j] + p[j]);
//		v[i] = res;
//	}
//
//	return v[l];
//}
//
//int two_pointer(const vector<int> v, const int target)
//{
//	// int sum = accumulate(v.begin(), v.end(), 0);
//	int interval = v[0];// accumulate(v.begin() + s, v.begin() + e, 0);
//	int count = 0, v_size = static_cast<int>(v.size());
//	int s = 0, e = 0;
//
//	while (e != v_size)
//	{
//		if (target > interval)
//		{
//			++e;
//			if (e == v_size) 
//				break;
//			interval += v[e];
//		}
//		else if (target <= interval)
//		{
//			if (target == interval)
//				++count;
//			++s;
//			interval -= v[s];
//		}
//		
//	}
//
//	return count;
//}

//int main()
//{
//	//vector<int> p = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
//	//int k = 4;
//	//auto i = cut_rod(p, k);
//	//auto j = bottom_up_cut_rod(p, k);
//
//	return 0;
//}