#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
// dp[i] : 斐波那契数列第i项的值
int dp[31];

class Solution
{
public:
    int fib(int n)
    {
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};