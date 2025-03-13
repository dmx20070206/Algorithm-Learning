#include <iostream>
#include <vector>
#include <sstream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    string intToRoman(int num)
    {
        string str = to_string(num);

        str = string(4 - str.size(), '0') + str;

        string answer;
        int num0 = str[0] - '0';
        int num1 = str[1] - '0';
        int num2 = str[2] - '0';
        int num3 = str[3] - '0';

        // num0
        answer += string(num0, 'M');

        // num1
        if (num1 == 4)
        {
            answer += "CD";
        }
        else if (num1 == 9)
        {
            answer += "CM";
        }
        else
        {
            if (num1 >= 5)
            {
                num1 -= 5;
                answer += "D";
            }
            answer += string(num1, 'C');
        }

        // num2
        if (num2 == 4)
        {
            answer += "XL";
        }
        else if (num2 == 9)
        {
            answer += "XC";
        }
        else
        {
            if (num2 >= 5)
            {
                num2 -= 5;
                answer += "L";
            }
            answer += string(num2, 'X');
        }

        // num3
        if (num3 == 4)
        {
            answer += "IV";
        }
        else if (num3 == 9)
        {
            answer += "IX";
        }
        else
        {
            if (num3 >= 5)
            {
                num3 -= 5;
                answer += "V";
            }
            answer += string(num3, 'I');
        }

        return answer;
    }
};