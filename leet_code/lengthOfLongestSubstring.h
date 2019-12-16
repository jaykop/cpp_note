#include <set>
#include <string>

class Solution {
public:
	int lengthOfLongestSubstring(std::string s) {

		// init values
		int largest = 0;
		std::string accum;

		// loop until the end
		for (std::string::iterator it = s.begin(); it != s.end(); ++it) {

			auto found = accum.find(*it);

			// 
			if (!accum.empty() &&
				found != std::string::npos) {

				int so_far = static_cast<int>(accum.length());

				// update largest
				if (largest < so_far)
					largest = so_far;

				if (accum[accum.length() - 1] == *it) 
					accum.clear();

				else {

					std::string substr = accum.substr(found + 1, accum.length());

					accum = substr;
					accum += (*it);
				}
			}

			else
				accum += (*it);
		}

		int so_far = static_cast<int>(accum.length());
		if (largest < so_far)
			largest = so_far;

		return largest;
	}

};
