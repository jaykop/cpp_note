#include <string>

using namespace std;

class Solution
{
public:
	string convert(string s, int numRows) {

		// edge cased
		if (numRows == 1)
			return s;

		else {

			int bridge = numRows - 2;
			int len = int(s.length());

			auto begin = s.begin();
			const auto& last = s.end() - 1;

			string toReturn;

			for (int i = 0; i < numRows; i++) {

				int sum = i;
				int interval_head_tail = (numRows - 2) * 2 + 2; // 2, 4, 6, 8, ...

				// head and tail
				if (i == 0 || numRows - 1 == i) {
					while (sum < len)
					{
						toReturn += *(s.begin() + sum);
						sum += interval_head_tail;
					}
				}

				// unless
				else {
					int interval = interval_head_tail - i * 2;
					int remain = interval_head_tail - interval;

					int j = 1;
					while (sum < len) {

						toReturn += *(s.begin() + sum);

						if (j % 2)
							sum += interval;
						else
							sum += remain;

						j++;
					}
				}
			}

			return toReturn;
		}
	}
};

// 1 5 9 13 -> 4
// 2 4 6 8 10 12 14 -> 2
// 3 7 11 -> 4

// 1 7 13 -> 6
// 2 6 8 12 14 -> 4 2 4 2
// 3 5 9 11 -> 2 4 2
// 4 -> 6

// P          H
// A       S  I
// Y     I    R
// P  L       I  G
// A		  N

// 1 9 -> 8
// 2 8 10 -> 6 2
// 3 7 11 -> 4 4
// 4 6 12 14 -> 2 6
// 5 13 -> 8

// 1 11 -> 10
// 2 10 12 -> 8 2
// 3 9 13 -> 6 4
// 4 8 14 -> 4 6
// 5 7 -> 2 8
// 6 -> 10