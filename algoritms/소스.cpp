#include <vector>

using namespace std;

void qsort(vector<int>& v, int left, int right)
{
	int i = left, j = right;
	int mid = v[(i + j) / 2];
	while (i <= j)
	{
		while (v[i] < mid) ++i;
		while (mid < v[j]) --j;
		if (i <= j)
		{
			swap(v[i], v[j]);
			++i, --j;
		}
	}

	if (left < j) qsort(v, left, j);
	if (i < right) qsort(v, i, right);
}

bool binary_search(const vector<int>& v, int k)
{
	int i = 0, j = static_cast<int>(v.size());
	
	while (j - i >= 0)
	{
		int mid = (i + j) / 2;

		if (v[mid] == k)
			return true;
		else if (v[mid] < k)
			i = mid + 1;
		else // (k < v[mid])
			j = mid - 1;
	}

	return false;	
}

int main()
{
	vector<int> v = {65,4,46,8,4,-67,5,30,-98,-0,90,9080,-767,9,4};
	qsort(v, 0, v.size() - 1);
	auto i = binary_search(v, -30);

	return 0;
}