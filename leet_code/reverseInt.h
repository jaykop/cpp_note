#include <vector>
#include <cmath>

class Solution {
public:

	int reverse(int x) {

		bool negative = false; // signed

		// check if it is negative int
		if (x < 0) {
			negative = true;
			x *= -1;
		}

		if (x < 10) {

			if (negative)
				x *= -1;

			return x;
		}

		std::vector<int> digits;
		int loops = 0;
		int sum = 0;

		// get digits save them into a vector
		while (x) {
			int detach = x % 10;
			x -= detach; // remove remnant
			x /= 10;
			if ((sum > INT_MAX / 10 || (sum == INT_MAX / 10 && detach > 7)) && !negative) 
				return 0;
			if ((-sum < (INT_MIN / 10) || (-sum == (INT_MIN / 10) && detach < -8)) && negative) 
				return 0;
			sum = detach + sum * 10;
		}

		if (negative)
			sum *= -1;

		return sum;
	}
};

//class Solution {
//public:
//	int reverse(int x) {
//		int rev = 0;
//		while (x != 0) {
//			int pop = x % 10;
//			x /= 10;
//			if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
//			if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
//			rev = rev * 10 + pop;
//		}
//		return rev;
//	}
//};