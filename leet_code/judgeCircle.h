class Solution {
public:
    bool judgeCircle(string moves) {
        
        int ud = 0, lr = 0;
        for (auto c : moves) {
            
            switch (c) {
                case 'U':
                    ud++;
                    break;
                case 'D':
                    ud--;
                    break;
                case 'R':
                    lr++;
                    break;
                case 'L':
                    lr--;
                    break;
            }
        }
        
        if (!ud && !lr) return true;
        return false;
    }
};