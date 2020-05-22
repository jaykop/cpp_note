#include "checkInclusion.h"

int main() {

	string s1 = "abcdxabcde", s2 = "abcdeabcdx";
	Solution a;
	auto b = a.checkInclusion(s1, s2);

	return 0;
}