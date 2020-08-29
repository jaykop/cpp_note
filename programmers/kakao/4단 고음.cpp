void rec(long l, int& count, bool t, bool d, int stack)
{
	if (stack == 3)
		t = true;

	if (l == 1 && t && d)
		count += 1;
	
	else if (l > 1)
	{
		if (l % 3 == 0)
		{
			if (stack == 2)
				rec(l / 3, count, t, true, stack + 1);
			else
				rec(l / 3, count, t, true, 0);

			if (stack == 2)
				rec(l - 1, count, t, false, 0);
			else
				rec(l - 1, count, t, false, stack + 1);
		}

		else
		{
			if (stack == 2)
				rec(l - 1, count, t, false, 0);
			else
				rec(l - 1, count, t, false, stack + 1);
		}
	}
}

int solution(int n) {
	long l = static_cast<long>(n);
	int count = 0;
	bool t = false;
	rec(l, count, t, false, 0);
	return count;
}

int main()
{
	auto a = solution(24);
	return 0;
}