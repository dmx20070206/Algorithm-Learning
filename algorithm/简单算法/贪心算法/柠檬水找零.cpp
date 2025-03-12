// https://leetcode.cn/problems/lemonade-change/description/

#include <iostream>
#include <vector>
#include <functional>
using namespace std;

class Solution
{
public:
    bool lemonadeChange(vector<int> &bills)
    {
        int cur5Num = 0;
        int cur10Num = 0;

        for (int i = 0; i < bills.size(); i++)
        {
            switch (bills[i])
            {
            case (5):
                cur5Num++;
                break;
            case (10):
                cur10Num++;
                if (cur5Num <= 0)
                    return false;
                cur5Num--;
                break;
            case (20):
                if (cur10Num >= 1 && cur5Num >= 1)
                {
                    cur5Num--;
                    cur10Num--;
                }
                else if (cur5Num >= 3)
                {
                    cur5Num -= 3;
                }
                else
                    return false;
                break;
            }
        }
        return true;
    }
};