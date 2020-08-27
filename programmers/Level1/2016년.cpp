#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    const string days[7] = {"THU", "FRI", "SAT", "SUN", "MON", "TUE", "WED"};
    const int dates[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    int sum = 0;
    for (int i = 0; i < a - 1; ++i)
        sum += dates[i];
    sum += b;
    
    return days[sum % 7];
}