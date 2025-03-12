#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int T, M;
    cin >> T >> M;

    // weight value
    vector<int> weight(M, 0);
    vector<int> value(M, 0);
    for (int i = 0; i < M; i++)
    {
        cin >> weight[i] >> value[i];
    }

    int dp[101][1001];
    for (int i = weight[0]; i <= T; i++)
    {
        dp[0][i] = value[0];
    }

    for (int i = 1; i < M; i++)
    {
        for (int j = 0; j <= T; j++)
        {
            if (j >= weight[i])
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    cout << dp[M - 1][T] << endl;
    return 0;
}