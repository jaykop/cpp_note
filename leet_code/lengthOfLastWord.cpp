class Solution {
public:
    int lengthOfLastWord(string s) {

        int ans = 0;
        bool start_counting = false;

        int size = int(s.length());
        for (int i = size - 1; i >= 0; --i)
        {
            if (!start_counting)
            {
                if (s[i] != ' ')
                {
                    start_counting = true;
                    ++ans;
                }
            }

            else // if (start_counting)
            {
                if (s[i] == ' ')
                    break;

                ++ans;
            }
        }

        return ans;
    }
};