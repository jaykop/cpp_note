class Solution
{
public:
    int minAddToMakeValid(string S)
    {
        string toRemove("()");
        size_t pos = S.find(toRemove);
        
        while (pos != string::npos) {
            S.erase(pos, toRemove.length());
            pos = S.find(toRemove);
        }

        return int(S.size());
    }
};

// more efficient answer
// int minAddToMakeValid(char * S){
//     int bra = 0, ket = 0;
//     for(int k = 0;S[k] != '\0';k++) {
//         if(S[k] == ')') {
//             bra > 0 ? bra-- : ket++;
//         } else {
//             bra++;
//         }
//     }
//     return bra + ket;
// }