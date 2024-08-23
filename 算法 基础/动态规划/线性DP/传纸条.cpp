#include <iostream>
#include <vector>
using namespace std;

int dp[55][55][100];
// 1 (x1, y1) 2 (x2, y2)
// x + y - 2 = num

int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> arr(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            cin >> arr[i][j];

    int nums = n + m - 2;
    dp[1][1][0] = arr[1][1];
    for (int i = 0; i < nums; i++)
    {
        for (int x1 = 1; x1 <= n; x1++)
        {
            for (int x2 = 1; x2 <= n; x2++)
            {
                int y1 = i + 2 - x1;
                int y2 = i + 2 - x2;

                if (y1 <= 0 || y2 <= 0 || y1 > m || y2 > m)
                    continue;

                int case1 = 0, case2 = 0, case3 = 0, case4 = 0;

                // right right
                if (x1 != n && x2 != n)
                    case1 = x1 + 1 == x2 + 1 && y1 == y2 ? dp[x1][x2][i] + arr[y1][x1 + 1] : dp[x1][x2][i] + arr[y1][x1 + 1] + arr[y2][x2 + 1];
                dp[x1 + 1][x2 + 1][i + 1] = max(dp[x1 + 1][x2 + 1][i + 1], case1);

                // right down
                if (x1 != n && y2 != m)
                    case2 = x1 + 1 == x2 && y1 == y2 + 1 ? dp[x1][x2][i] + arr[y1][x1 + 1] : dp[x1][x2][i] + arr[y1][x1 + 1] + arr[y2 + 1][x2];
                dp[x1 + 1][x2][i + 1] = max(dp[x1 + 1][x2][i + 1], case2);

                // down right
                if (y1 != m && x2 != n)
                    case3 = x1 == x2 + 1 && y1 + 1 == y2 ? dp[x1][x2][i] + arr[y1 + 1][x1] : dp[x1][x2][i] + arr[y1 + 1][x1] + arr[y2][x2 + 1];
                dp[x1][x2 + 1][i + 1] = max(dp[x1][x2 + 1][i + 1], case3);

                // down down
                if (y1 != m && y2 != m)
                    case4 = x1 == x2 && y1 + 1 == y2 + 1 ? dp[x1][x2][i] + arr[y1 + 1][x1] : dp[x1][x2][i] + arr[y1 + 1][x1] + arr[y2 + 1][x2];
                dp[x1][x2][i + 1] = max(dp[x1][x2][i + 1], case4);
            }
        }
    }

    int answer = dp[n][n][nums];
    cout << answer << endl;
    return 0;
}