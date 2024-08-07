#include <iostream>
#include <vector>
using namespace std;
// dp[i]表示跳到第i个台阶的最小花费
int dp[1001];

class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        dp[0] = 0;
        dp[1] = 0;
        for (int i = 2; i <= cost.size(); i++)
        {
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }
        return dp[cost.size()];
    }
};