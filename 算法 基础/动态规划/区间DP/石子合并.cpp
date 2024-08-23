#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int dp[305][305];
int main()
{
    int N;
    cin >> N;
    vector<int> stones(N + 1, 0);
    for (int i = 1; i <= N; i++)
        cin >> stones[i];

    memset(dp, 0x3f, sizeof dp);
    for (int i = 0; i <= N; i++)
        dp[i][i] = 0;

    vector<int> frontSum(N + 1, 0);
    for (int i = 1; i <= N; i++)
    {
        frontSum[i] = stones[i] + frontSum[i - 1];
    }

    for (int len = 2; len <= N; len++)
    {
        for (int left = 1; left <= N - len + 1; left++)
        {
            int right = len + left - 1;
            // dp[left][right]: [left, right]中的全部石头合到一起需要的最小代价
            int minSum = INT32_MAX;
            for (int k = left; k < right; k++)
            {
                minSum = min(minSum, dp[left][k] + dp[k + 1][right]);
            }
            minSum += frontSum[right] - frontSum[left - 1];
            dp[left][right] = minSum;
        }
    }

    cout << dp[1][N] << endl;
    return 0;
}