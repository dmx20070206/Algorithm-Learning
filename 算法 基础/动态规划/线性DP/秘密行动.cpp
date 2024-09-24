#include <iostream>
#include <vector>
using namespace std;

int dp[10005][2];
// dp[i][0]: i层，可以使用技能的最小时间
// dp[i][1]: i层，不能使用技能的最小时间
// dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + heights[i];
// dp[i][1] = min(dp[i - 1][0], dp[i - 2][0]);
int main()
{
    int N;
    cin >> N;
    vector<int> heights(N + 1, 0);
    for (int i = 1; i <= N; i++)
        cin >> heights[i];

    for (int i = 1; i <= N; i++)
    {
        dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + heights[i];
        dp[i][1] = min(dp[i - 1][0], dp[i - 2][0]);
    }
    cout << min(dp[N][0], dp[N][1]) << endl;
    return 0;
}