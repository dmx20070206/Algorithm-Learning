#include <iostream>
#include <vector>
using namespace std;
// dp[i]表示取得1~i的数字进行游戏能获得的最大分数
int dp[10001];

class Solution
{
public:
    int deleteAndEarn(vector<int> &nums)
    {
        vector<int> count(10001, 0);
        int maxNum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            count[nums[i]]++;
            maxNum = max(nums[i], maxNum);
        }
        dp[0] = 0;
        dp[1] = count[1];
        for (int num = 2; num <= maxNum; num++)
        {
            dp[num] = max(dp[num - 2] + count[num] * num, dp[num - 1]);
        }
        return dp[maxNum];
    }
};
