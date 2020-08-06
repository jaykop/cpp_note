class Solution {
public:
    double average(vector<int>& salary) {
        
        double dmax = double(max(salary[0], salary[1]));
        double dmin = double(min(salary[0], salary[1]));
        double res = 0;
        
        for (int i = 0; i < salary.size(); ++i)
        {
            if (double(salary[i]) > dmax)
                dmax = salary[i];
            
            else if (double(salary[i]) < dmin)
                dmin = salary[i];
            
            res += salary[i];
        }
        
        return (res - dmin - dmax) / (salary.size()-2);
    }
};