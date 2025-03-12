#include <iostream>
#include <vector>
using namespace std;
// dp[i]表示在前i个房间打劫能拿到的最大资金
int dp[1001];

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        dp[0] = 0;
        dp[1] = nums[0];
        for (int i = 2; i <= nums.size(); i++)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
        }
        return dp[nums.size()];
    }
};