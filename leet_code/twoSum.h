#include <vector>
#include <map>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> toReturn;
		multimap<int, int> opponent, table;

		float target_half = float(target) * 0.5f;
		int index = 0;
		for (const auto& i : nums) {

			opponent.insert({ i, target - i });

			if (float(i) == target_half) {
				toReturn.push_back(index);
				if (toReturn.size() == 2)
					return toReturn;
			}

			table.insert({ i, index++ });
		}

		toReturn.clear();
		for (const auto& i : nums) {

			auto a = table.lower_bound(opponent.lower_bound(i)->second);
			auto b = table.lower_bound(i);
			if (a->second != b->second
				&& a->first + b->first == target) {
				toReturn.push_back(a->second);
				toReturn.push_back(b->second);
				break;
			}
		}

		for (auto i : toReturn)
			printf("%i", i);
		return toReturn;
	}
};

int main()
{
	vector<int> a = { -3, 4, 3, 90 };
	int target = 0;
	Solution sol;
	sol.twoSum(a, target);
	return 0;
}