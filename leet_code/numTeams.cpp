class Solution {
public:
    int numTeams(vector<int>& rating) {
        
        int toReturn = 0;
        int size = int(rating.size());
        for (int i = 0; i < size - 2; i++)
        {    
            for (int j = i + 1; j < size - 1; j++)
            {
                int count = 0;
                for (int k = j + 1; k < size; k++)
                {
                    int a = rating[i];
                    int b = rating[j];
                    int c = rating[k];
                    
                    if ((a < b && b < c )
                        || (a > b && b > c ))
                    {
                        count++;
                    }
                }
                toReturn += count;
            }
        }
        
        return toReturn;
    }
};