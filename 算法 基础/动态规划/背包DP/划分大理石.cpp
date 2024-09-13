#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

bool dp[120000];
int main()
{
    vector<int> nums(6, 0);
    vector<bool> flags(6, false);
    vector<int> weights;

    while (true)
    {
        // reset
        for (int i = 0; i < 6; i++)
        {
            flags[i] = false;
        }
        weights.resize(0);
        bool breakFlag = true;
        for (int i = 0; i < 6; i++)
        {
            cin >> nums[i];
            if (nums[i] != 0)
                breakFlag = false;
        }
        if (breakFlag)
            break;

        // 计算背包容量
        int sum = nums[0] + nums[1] * 2 + nums[2] * 3 + nums[3] * 4 + nums[4] * 5 + nums[5] * 6;
        if (sum % 2 != 0)
        {
            cout << "Can't" << endl;
            continue;
        }
        sum /= 2;

        // 生成全部物品
        int k = 1;
        while (flags[0] == false || flags[1] == false || flags[2] == false || flags[3] == false || flags[4] == false || flags[5] == false)
        {
            for (int i = 1; i <= 6; i++)
            {
                if (nums[i - 1] < k)
                {
                    flags[i - 1] = true;
                }
                if (!flags[i - 1])
                {
                    weights.push_back(k * i);
                    nums[i - 1] -= k;
                }
            }
            k *= 2;
        }
        for (int i = 1; i <= 6; i++)
        {
            if (nums[i - 1] > 0)
                weights.push_back(nums[i - 1] * i);
        }

        // 背包DP部分
        // 初始化
        memset(dp, false, sizeof dp);
        dp[weights[0]] = true;
        dp[0] = true;

        int num = weights.size();
        for (int i = 1; i < num; i++)
        {
            for (int j = sum; j >= 1; j--)
            {
                if (j >= weights[i])
                    dp[j] = dp[j] || dp[j - weights[i]];
            }
        }

        if (dp[sum])
        {
            cout << "Can" << endl;
        }
        else
        {
            cout << "Can't" << endl;
        }
    }
    return 0;
}