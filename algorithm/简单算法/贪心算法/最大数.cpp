#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
using namespace std;

class Compare
{
public:
    bool operator()(int &num1, int &num2)
    {
        string str1 = to_string(num1);
        string str2 = to_string(num2);

        return str1 + str2 > str2 + str1;
    }
};

class Solution
{
public:
    string largestNumber(vector<int> &nums)
    {
        sort(nums.begin(), nums.end(), Compare());
        string str;
        for (int i = 0; i < nums.size(); i++)
        {
            str += to_string(nums[i]);
        }
        if (str[0] == '0')
            return "0";
        return str;
    }
};