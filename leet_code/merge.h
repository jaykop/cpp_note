#pragma once
#include <vector>

using namespace std;

// bad answer
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        if (!intervals.empty())
        {
            bool to_check = true;

            while (to_check)
            {
                for (auto it1 = intervals.begin();
                    it1 != intervals.end() - 1; ++it1)
                {
                    if (!it1->empty())
                    {
                        for (auto it2 = it1 + 1;
                            !it1->empty() && it2 != intervals.end(); ++it2)
                        {
                            if (!it2->empty())
                            {
                                int it1_back = it1->back();
                                int it2_back = it2->back();

                                if (it1->back() <= it2->back())
                                {
                                    if (it2->front() <= it1->front())
                                        it1->clear();
                                    else if (it1->back() >= it2->front())
                                    {
                                        it1->back() = it2->back();
                                        it2->clear();
                                    }

                                }
                                else if (it2->back() <= it1->back())
                                {
                                    if (it1->front() <= it2->front())
                                        it2->clear();
                                    else if (it2->back() >= it1->front())
                                    {
                                        it2->back() = it1->back();
                                        it1->clear();
                                    }
                                }
                            }
                        }
                    }
                }
                
                to_check = false;

                for (auto it = intervals.begin();
                    it != intervals.end(); )
                    if (it->empty())
                    {
                        it = intervals.erase(it);
                        to_check = true;
                    }
                    else
                        ++it;

            }
        }

        return intervals;
    }
};