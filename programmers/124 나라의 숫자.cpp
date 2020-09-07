#include <string>
#include <vector>

using namespace std;

string solution(int n) {

    string answer = "";
    int count = 0;

    while (n > 0) {

        int coeff = 3;
        int sum = 0;

        while (n > sum + coeff)
        {
            sum += coeff;
            coeff *= 3;
        }

        coeff /= 3;

        int offset = -1;
        for (int i = 1; i <= 3; ++i)
        {
            if (n <= sum + coeff * i)
            {
                offset = i;
                break;
            }
        }

        switch (offset)
        {
        case 1: answer += '1';
            break;

        case 2: answer += '2';
            break;

        case 3: answer += '4';
            break;
        }

        n -= coeff * offset;

    }
    
    return answer;
}

int main()
{
    solution(10);
    return 0;
}