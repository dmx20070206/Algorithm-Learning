#include <iostream>
#include <vector>
#include <string.h>
#include <cmath>
using namespace std;

const int NUM = 1005;
int dp[NUM][NUM];
int nums[NUM];

int main()
{
    int N, P;
    cin >> N >> P;

    memset(dp, 0, sizeof dp);
    memset(nums, 0, sizeof nums);

    for (int i = 0; i < N; i++)
        cin >> nums[i];

    // init
    for (int i = 0; i < N; i++)
        dp[i][0] = nums[i];

    int k = log2(N);

    // dp[i][j] = max(dp[i][j - 1], dp[i + 2 ^ (j - 1)][j - 1])
    for (int j = 1; j <= k; j++)
    {
        for (int i = 0; i <= N - (1 << j); i++)
        {
            dp[i][j] = max(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
        }
    }

    for (int i = 0; i < P; i++)
    {
        int L, R;
        cin >> L >> R;
        L--;
        R--;

        // len = R - L + 1, 2 ^ k < len <= 2 ^ (k + 1)
        k = log2(R - L + 1);

        // L -> L + 2 ^ k - 1
        // R - 2 ^ k + 1 -> R
        cout << max(dp[L][k], dp[R - (1 << k) + 1][k]) << endl;
    }
}