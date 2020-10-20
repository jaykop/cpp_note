#include <vector>
#include <iostream>
#include <set>

using namespace std;

int main()
{
	set<int> s;
	int size = -1;
	scanf_s("%d", &size);

	for (int i = 0; i < size; i++)
	{
		int n = -1;
		scanf_s("%d", &n);
		s.insert(n);
	}

	scanf_s("%d", &size);

	//v2.resize(size);
	for (int i = 0; i < size; i++)
	{
		int n = -1;
		scanf_s("%d", &n);
		if (s.find(n) != s.end())
			cout << "1\n";
		else
			cout << "0\n";
	}

	return 0;
}