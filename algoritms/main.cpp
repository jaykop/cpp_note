/*
Sol2. FSM을 활용한다.
FSM을 작성하여 이에 맞게 상태를 전이시킨다. 본 코드에서는 비트마스킹을 추가로 활용하였으나 반드시 필요한 것은 아니다.
입력의 끝까지 읽어들였을 때 가능한 상태가 존재한다면 SUBMARINE, 아니면 NOISE이다.
*/
// #include <bits/stdc++.h>
#include <iostream>
using namespace std;

int state[999];//FSM BitMasking

int main(void) {

    string s;
    cin >> s;
    s += "|"; //Prevent SegmentFault
    state[0] = 1; //Bin : 0 0 0 0 0 1
    for (int i = 0; i < s.size() - 1; i++) {

        if (state[i] & 1) {// 'Initial'

            //Bin: 000010
            if (s[i] == '1')
                state[i + 1] |= 2;         

            //Bin: 100000
            if (s[i] == '0' && s[i + 1] == '1')
                state[i + 2] |= 32;  
        }
        if (state[i] & 2) {//stateate 'A'

            //Bin: 000100
            if (s[i] == '0')
                state[i + 1] |= 4;
        }
        if (state[i] & 4) {//stateate 'B'

            //Bin: 001000
            if (s[i] == '0')
                state[i + 1] |= 8;                
        }
        if (state[i] & 8) {//stateate 'C'

            //Bin: 001000
            if (s[i] == '0')
                state[i + 1] |= 8;                

            //Bin: 010000
            if (s[i] == '1')
                state[i + 1] |= 16;
        }
        if (state[i] & 16) {//stateate 'D'

            //Bin: 010010
            if (s[i] == '1')
                state[i + 1] |= 18;            

            //Bin: 100000
            if (s[i] == '0' && s[i + 1] == '1')
                state[i + 2] |= 32;  
        }
        if (state[i] & 32) {//stateate 'E'

            //Bin: 000001
            if (s[i] == '1')
                state[i + 1] |= 2;      

            //Bin: 100000
            if (s[i] == '0' && s[i + 1] == '1')
                state[i + 2] |= 32;  
        }
    }

    cout << ((state[s.size() - 1] & 48) ? "SUBMARINE" : "NOISE");
}

//
//#include <vector>
//#include <iostream>
//
//using namespace std;
//
//void qsort(vector<int>& v, int left, int right)
//{
//    int i = left, j = right;
//    int mid = v[(i + j) / 2];
//    while (i <= j)
//    {
//        while (v[i] < mid) ++i;
//        while (mid < v[j]) --j;
//        if (i <= j)
//        {
//            swap(v[i], v[j]);
//            ++i; --j;
//        }
//    }
//
//    if (left < j) qsort(v, left, j);
//    if (i < right) qsort(v, i, right);
//}
//
//bool binary_search(const vector<int>& v,
//    int i, int j,
//    const int k)
//{
//    while (j - i >= 0)
//    {
//        int mid = (i + j) / 2;
//        if (v[mid] == k) return true;
//        else if (v[mid] < k) i = mid + 1;
//        else // (k < v[mid]) 
//            j = mid - 1;
//    }
//
//    return false;
//}
//
//int main()
//{
//    int v_size = -1;
//    scanf("%d", &v_size);
//    vector<int> v;
//    for (int i = 0; i < v_size; i++)
//    {
//        int n = -1;
//        scanf("%d", &n);
//        v.push_back(n);
//    }
//
//    qsort(v, 0, v_size - 1);
//    int size = -1;
//    scanf("%d", &size);
//
//    for (int i = 0; i < size; ++i)
//    {
//        int n = -1;
//        scanf("%d", &n);
//        if (binary_search(v, 0, v_size - 1, n))
//            cout << "1\n";
//        else
//            cout << "0\n";
//    }
//
//    return 0;
//}

//#include <vector>
//#include <iostream>
//
//using namespace std;
//
//void qsort(vector<int>& v, int left, int right)
//{
//    int i = left, j = right;
//    int mid = v[(left + right) / 2];
//    while (i <= j)
//    {
//        while (mid < v[i])
//            ++i;
//        while (mid > v[j])
//            --j;
//        if (i <= j)
//        {
//            swap(v[j], v[i]);
//            ++i; --j;
//        }
//    }
//
//    if (left < i) qsort(v, left, mid - 1);
//    if (j < right) qsort(v, mid + 1, right);
//}
//
//int main()
//{
//    vector<int> v = { 3,56,4,3467,8,54,32,4,1};
//    qsort(v, 0, v.size() - 1);
//    return 0;
//}

//#include <iostream>
//
//using namespace std;
//
//int main()
//{
//    int n = -1;
//    scanf("%d", &n);
//
//    int s = 1, e = 1;
//    bool exist = false;
//
//    while (1)
//    {
//        int res = e * e - s * s;
//
//        if (res >= n)
//        {
//            if (e - s == 1 && res > n)
//                break;
//            else
//                ++s;
//        }
//        else // res < n
//            ++e;
//
//        if (res == n)
//        {
//            cout << e << "\n";
//            exist = true;
//        }
//    }
//
//    if (!exist) cout << -1;
//
//    return 0;
//}

//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int main()
//{
//    vector<vector<int>> map;
//    int row = -1;
//    scanf("%d", &row);
//
//    for (int i = 0; i < row; ++i)
//    {
//        vector<int> v;
//        for (int j = 0; j < 3; ++j)
//        {
//            int n = -1;
//            scanf("%d", &n);
//            v.push_back(n);
//        }
//        map.emplace_back(v);
//    }
//
//    int max_val = 0, min_val = 0;
//    int i = 0;
//    vector<int> pre_min = { 0, 0, 0 }, cur_min = { 0, 0, 0 },
//        pre_max = { 0, 0, 0 }, cur_max = { 0, 0, 0 };
//
//    while (i < row)
//    {
//        cur_max[0] = max(pre_max[0] + map[i][0], pre_max[1] + map[i][1]);
//        cur_max[1] = max(pre_max[1] + map[i][1],
//            max(pre_max[2] + map[i][2], pre_max[0] + map[i][0]));
//        cur_max[2] = max(pre_max[2] + map[i][2], pre_max[1] + map[i][1]);
//        max_val = max(cur_max[0], max(cur_max[1], cur_max[2]));
//
//        cur_min[0] = min(pre_min[0] + map[i][0], pre_min[1] + map[i][1]);
//        cur_min[1] = min(pre_min[1] + map[i][1],
//            min(pre_min[2] + map[i][2], pre_min[0] + map[i][0]));
//        cur_min[2] = min(pre_min[2] + map[i][2], pre_min[1] + map[i][1]);
//        min_val = min(cur_min[0], min(cur_min[1], cur_min[2]));
//
//        pre_min = cur_min;
//        pre_max = cur_max;
//
//        ++i;
//    }
//
//    cout << max_val << " " << min_val;
//
//    return 0;
//}

//#include <vector>
//#include <iostream>
//
//using namespace std;
//
//int main()
//{
//	int size, target;
//	scanf("%d", &size);
//	scanf("%d", &target);
//	vector<int> v;
//	for (int i = 0; i < size; ++i)
//	{
//		int n;
//		scanf("%d", &n);
//		v.push_back(n);
//	}
//
//	int sum = 0, s = 0, e = 0, min = size;
//	bool edited = false;
//
//	while (1)
//	{
//		if (sum > target)
//		{
//			sum -= v[s];
//			++s;
//		}
//
//		else if (e == size)
//			break;
//
//		else // sum <= target
//		{
//			sum += v[e];
//			++e;
//		}
//		int len = e - s;
//		if (target <= sum && min >= len)
//		{
//			min = len;
//			edited = true;
//		}
//	}
//
//	if (!edited) min = 0;
//
//	cout << min;
//
//	return 0;
//}

//
//bool prime(int k)
//{
//	if (k == 2)
//		return true;
//
//	else if (k % 2 == 0) 
//		return false;
//
//	else
//	{
//		for (int i = 3; i < k; i += 2)
//			if (k % i == 0) 
//				return false;
//
//		return true;
//	}
//}
//
//int main()
//{
//	int n;
//	scanf_s("%d", &n);
//	// scanf("%d", &n);
//
//	vector<int> v(n + 1, 0), p;
//	int init = 0;
//	for (auto& i : v)
//		i = init++;
//
//	int range = sqrt(n);
//
//	for (int i = 2; i <= range; ++i)
//	{
//		if (v[i] == -1) continue;
//		else if (prime(i))
//		{
//			int cnt = i;
//			while (1)
//			{
//				cnt += i;
//				if (cnt > n) break;
//				v[cnt] = -1;
//			}
//		}
//		else
//			v[i] = -1;
//	}
//
//	for (auto i : v)
//		if (i >= 2) p.push_back(i);
//
//	int s = 0, e = 0, count = 0,
//		interval = 0, p_size = static_cast<int>(p.size());
//	
//	while (1)
//	{
//		if (interval > n)
//		{
//			interval -= p[s];
//			++s;
//		}
//
//		else if (e >= p_size)
//			break;
//
//		else // inteval <= n
//		{
//			interval += p[e];
//			++e;
//		}
//
//		if (interval == n)
//			++count;
//	}
//
//	cout << count;
//
//	return 0;
//}

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