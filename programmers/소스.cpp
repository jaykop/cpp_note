#include <string>
#include <vector>

using namespace std;

bool solution(vector<string> phone_book) {

    int size = phone_book.size();
    for (int i = 0; i < size - 1; ++i)
    {
        for (int j = i + 1; j < size; ++j)
        {
            string a, b;
            // longer always become a
            // shorter becomes b
            if (phone_book[j].length() > phone_book[i].length())
            {
                a = phone_book[j];
                b = phone_book[i];
            }
            else
            {
                a = phone_book[i];
                b = phone_book[j];
            }

            int len = b.length();
            string substr = a.substr(0, len - 1);
            if (substr == b)
                return false;
        }
    }
    return true;
}

int main()
{
    vector<string> v = { "119", "97674223", "1195524421" };
    solution(v);
}