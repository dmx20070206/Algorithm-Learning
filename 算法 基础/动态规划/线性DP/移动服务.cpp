#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int dp[1024][210][210];
int main()
{
    int L, N;
    cin >> L >> N;

    vector<vector<int>> cost(L + 1, vector<int>(L + 1, 0));
    for (int i = 1; i <= L; i++)
    {
        for (int j = 1; j <= L; j++)
        {
            cin >> cost[i][j];
        }
    }

    vector<int> request(N + 1, 0);
    for (int i = 1; i <= N; i++)
        cin >> request[i];
    request[0] = 3;

    memset(dp, 0x3f, sizeof dp);
    dp[0][1][2] = 0;
    for (int i = 0; i < N; i++)
    {
        for (int x = 1; x <= L; x++)
        {
            for (int y = 1; y <= L; y++)
            {
                if (x == y || x == request[i] || request[i] == y)
                    continue;

                // pi -> pi+1
                dp[i + 1][x][y] = min(dp[i + 1][x][y], dp[i][x][y] + cost[request[i]][request[i + 1]]);

                // x -> pi+1
                dp[i + 1][request[i]][y] = min(dp[i + 1][request[i]][y], dp[i][x][y] + cost[x][request[i + 1]]);

                // y -> pi+1
                dp[i + 1][x][request[i]] = min(dp[i + 1][x][request[i]], dp[i][x][y] + cost[y][request[i + 1]]);
            }
        }
    }

    int answer = INT32_MAX;
    for (int i = 1; i <= L; i++)
    {
        for (int j = 1; j <= L; j++)
        {
            if (i == j || j == request[N] || request[N] == i)
                continue;
            answer = min(answer, dp[N][i][j]);
        }
    }

    cout << answer << endl;
    return 0;
}