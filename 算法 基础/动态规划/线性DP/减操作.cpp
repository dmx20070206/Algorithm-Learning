#include <iostream>
#include <vector>
using namespace std;

#define offset 10000
int dp[105][2 * offset];
int main()
{
    // 输入数据
    int n, target;
    cin >> n >> target;
    vector<int> nums(n, 0);
    vector<int> answer(n, 0);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
        sum += nums[i];
    }

    // 求目标和的组成
    dp[0][nums[0] + offset] = 1;
    dp[1][nums[0] - nums[1] + offset] = -1;
    for (int i = 2; i < n; i++)
    {
        for (int j = 0; j <= 2 * offset; j++)
        {
            if (dp[i - 1][j])
            {
                dp[i][j + nums[i]] = 1;
                dp[i][j - nums[i]] = -1;
            }
        }
    }

    // 求解符号
    int curSum = target;
    for (int i = n - 1; i >= 0; i--)
    {
        answer[i] = dp[i][curSum + offset];
        curSum = curSum - dp[i][curSum + offset] * nums[i];
    }

    // 最终答案
    vector<int> finalAnswer;

    // 如果当前符号为+，则上一个元素必定要操作
    int cnt = 0;
    for (int i = 2; i < (int)answer.size(); i++)
    {
        if (answer[i] == 1)
        {
            cout << i - cnt << endl;
            cnt++;
        }
    }

    // 从头逐个处理需要减去的元素
    for (int i = 0; i < (int)answer.size(); i++)
    {
        if (answer[i] == -1)
            cout << 1 << endl;
    }

    return 0;
}