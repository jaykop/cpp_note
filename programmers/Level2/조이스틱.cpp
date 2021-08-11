#include <string>
#include <vector>

using namespace std;

int find_closest_a(const string& name, int current)
{
    int dist = 1;
}

int solution(string name) {

    int len = name.length();
    int lenHalf = len / 2;
    int count = 0; 
    
    for (int i = 0; i < len; ++i)
    {
        if (name[i] == 'A')
        {
            ++count;
        }
    }

    if (count == len)
        return 0;

    count = 0;
    const char half = ('Z' - 'A') / 2 + 'A';

    bool moveRight = first_a > len - last_a;

    for (int i = 0, loop = 0; loop < len; ++loop)
    {
        if (name[i] == 'A')
            ;
        else if (name[i] <= half)
            count += (name[i] - 'A');
        else
            count += 'Z' - name[i] + 1;

        ++count;
        i = moveRight ? i + 1 : (i + len - 1) % len;
    }

    return count - 1;
}

int main()
{
    solution("ABABAAAAAAABA");
    return 0;
}