
/*
Given a roman numeral, convert it to an integer. WIP
*/
#include <iostream>
#include <string>
#include <map>
using namespace std;

class Solution
{
public:
    int romanToInt(string s)
    {
        unordered_map<string, int> {
            {"M", 1000},
            {"D", 500},
            {"C", 100},
            {"L", 50},
            {"X", 10},
            {"V", 5},
            {"I", 1},
            {"CM", 900},
            {"CD", 400},
            {"XC", 90},
            {"XL", 40},
            {"IX", 9},
            {"IV", 4},

        };
        int total = 0;
        int i = 0;

        while (i < size(s))
        {
            if ()
            {
            }
            else
            {
                total += romanVal.find(s[i]);
                i++;
            }
        }
    }
};
