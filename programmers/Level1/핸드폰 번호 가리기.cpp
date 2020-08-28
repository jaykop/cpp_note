#include <string>
#include <vector>

using namespace std;

string solution(string cell) {
    size_t size = cell.length();
    size_t last = size - 4;
    for (int i = 0; i < last; ++i)
        cell[i] = '*';
    return cell;
}