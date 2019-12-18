class Solution {
public:
    int subtractProductAndSum(int n) {
        
        vector<int> parsed;
        while (n) {
            int detach = n % 10;
            parsed.push_back(detach);
            n -= detach;
            n /= 10;
        }
        
        int mul = 1;
        int sum = 0;
        for (const auto& i : parsed){
            
            mul *= i;
            sum += i;
        }
        
        return  mul - sum;
    }
};