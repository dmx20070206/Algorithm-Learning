// https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/description/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int answer = 0;
        vector<int> nums;
        for (int i = 1; i < prices.size(); i++)
        {
            nums.push_back(prices[i] - prices[i - 1]);
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
                answer += nums[i];
        }
        return answer;
    }
};