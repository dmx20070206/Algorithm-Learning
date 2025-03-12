#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int monotoneIncreasingDigits(int n)
    {
        string str = to_string(n);

        int flag = str.size();
        for (int i = str.size() - 1; i >= 1; i--)
        {
            if (str[i - 1] > str[i])
            {
                flag = i;
                str[i - 1]--;
            }
        }
        for (int i = flag; i < str.size(); i++)
        {
            str[i] = '9';
        }
        return stoi(str);
    }
};