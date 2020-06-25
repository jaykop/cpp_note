#pragma once
#include <string>
using namespace std;

class Solution {
public:

    void add(string& a, string& b,
        int max, int min)
    {
        int offset = max - min;
        string up = "0";

        for (int i = min - 1; i >= 0; --i)
        {
            if (a[i + offset] == '1'
                && b[i] == '1')
            {
                if (up == "0")
                {
                    a[i + offset] = '0';
                    up = "1";
                }
            }
            else if (a[i + offset] == '0'
                && b[i] == '0')
            {
                if (up == "1")
                {
                    a[i + offset] = '1';
                    up = "0";
                }
            }
            else
            {
                if (up == "1")
                {
                    a[i + offset] = '0';
                }
                else
                {
                    a[i + offset] = '1';
                }
            }
        }

        if (up == "1")
            for (int i = max - min - 1; i >= 0; --i)
            {
                if (a[i] == '1')
                {
                    a[i] = '0';
                }
                else
                {
                    a[i] = '1';
                    up = "0";
                    break;
                }
            }

        if (up == "1")
            a.insert(0, up);
    }

    string addBinary(string a, string b) {

        if (a.length() > b.length())
        {
            add(a, b, a.length(), b.length());
            return a;
        }

        else
        {
            add(b, a, b.length(), a.length());
            return b;
        }
    }
};

// other solution

class Solution
{
public:
    string addBinary(string a, string b)
    {
        string s = "";

        int c = 0, // new digit to add
            i = a.size() - 1, j = b.size() - 1;
        while (i >= 0 // valid index
            || j >= 0 // valid index
            || c == 1) // digit to add still left
        {
            c += i >= 0 ? a[i--] - '0' : 0; // need to check if index is valid ? add to c
            c += j >= 0 ? b[j--] - '0' : 0; // need to check if index is valid ? add to c
            s = char(c % 2 + '0') + s; // convert to char and add to head
            c /= 2; // what a nice process
        }

        return s;
    }
};