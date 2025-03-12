#include <iostream>
#include <string.h>
using namespace std;

int weights[20][20];
int dp[1 << 20][20];

int main()
{
    memset(dp, 0x3f, sizeof dp);
    dp[1][0] = 0;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> weights[i][j];
        }
    }

    for (int i = 1; i < 1 << n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (i >> k & 1)
                    dp[i ^ 1 << j][j] = min(dp[i ^ 1 << j][j], dp[i][k] + weights[j][k]);
            }
        }
    }
    cout << dp[(1 << n) - 1][n - 1] << endl;

    return 0;
}