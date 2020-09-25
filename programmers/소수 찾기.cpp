#include <string>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

void rec(set<int>& v, string sofar, string left)
{
    if (left.empty())
        return;

    string copy(left);
    int size = static_cast<int>(copy.length());
    for (int i = 0; i < size; ++i)
    {
        left = copy;
        string new_sofar = sofar + left[i];
        v.insert(atoi(new_sofar.c_str()));
        left.erase(left.begin() + i);
        rec(v, new_sofar, left);
    }
}

bool check_prime(int n)
{
    if (n == 2)
        return true;
    else if (n % 2 == 0 || n <= 1)
        return false;
    else
    {
        int lim = (n / 2);
        for (int i = 3; i <= lim; ++i)
            if (n % i == 0)
                return false;

        return true;
    }
}

int solution(string numbers) {

    int answer = 0;

    set<int> list;
    rec(list, "", numbers);

    for (const auto& i : list)
        if (check_prime(i))
            ++answer;
    
    return answer;
}

int main()
{
    solution("2");
    return 0;
}