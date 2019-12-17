class Solution {
public:
    string convert(string s, int numRows) {
        
        // edge cased
        if (numRows < 3) {


        }

        else {

            int bridge = numRows - 2;
            int len = s.length();
            
            auto begin = s.begin();
            const auto& last = s.end() - 1;

            for (int i =0; i < numRows; i++) {

                
            }
        }
    }
};

// 1 5 9 13 -> 4
// 2 4 6 8 10 12 14 -> 2
// 3 7 11 -> 4

// 1713 -> 6
// 2681214 -> 4 2 4 2
// 35911 -> 2 4 2

// P          H
// A       S  I  
// Y     I    R
// P  L       I  G
// A		  N

// 19 -> 8
// 2810 -> 6 2
// 3711 -> 4 4
// 461214 ->2 6
// 513 -> 8

// 111 -> 10
// 21012 -> 8 2
// 3913 -> 6 4
// 4814 -> 4 6
// 57 -> 2 8
// 6 -> 10