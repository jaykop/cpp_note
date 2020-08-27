#include <string>
#include <vector>

using namespace std;

void convert(char& c, size_t i)
{
    if (i % 2 == 1 && 'A' <= c && c <= 'Z')
        c += 32;
    else if (i % 2 == 0 && 'a' <= c && c <= 'z')
        c -= 32;
}

string solution(string s) {
    
    size_t size = s.length();
    for (size_t i = 0, j = 0; i < size; ++i)
        if (s[i] != ' ')
        {
            convert(s[i], j++);
        }
        else
            j = 0;
    
    return s;
}