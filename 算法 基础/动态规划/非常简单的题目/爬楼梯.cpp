#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
// dp[i] : 跳到第i个格子的方法数
int dp[50];

class Solution
{
public:
    int climbStairs(int n)
    {
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};