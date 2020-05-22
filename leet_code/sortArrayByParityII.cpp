class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        
        vector<int> odds, evens;
        for (int i = 0 ; i < A.size(); i++)
        {
            // index = odd & val = even
            if (i % 2 && !(A[i] % 2))
            {
                if (!evens.empty())
                {
                    int temp = A[evens.back()];
                    A[evens.back()] = A[i];
                    A[i] = temp;
                    evens.pop_back();
                }
                else
                    odds.push_back(i);
            }
            // index = even & val = odd 
            else if (!(i % 2) && A[i] % 2)
            {
                if (!odds.empty())
                {
                    int temp = A[odds.back()];
                    A[odds.back()] = A[i];
                    A[i] = temp;
                    odds.pop_back();
                }
                else
                    evens.push_back(i);
            }
        }
        return A;            
    }
};