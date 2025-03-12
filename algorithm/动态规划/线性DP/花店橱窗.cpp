#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int dp[105][105];
int main()
{
    int F, V;
    cin >> F >> V;
    vector<vector<int>> values(F + 1, vector<int>(V + 1, 0));
    for (int i = 1; i <= F; i++)
    {
        for (int j = 1; j <= V; j++)
        {
            cin >> values[i][j];
        }
    }

    vector<vector<int>> path(F + 1, vector<int>(V + 1, 0));

    memset(dp, -0x3f, sizeof dp);
    int maxNum = INT16_MIN;
    for (int i = 1; i <= V; i++)
    {
        dp[1][i] = values[1][i];
    }

    for (int flowers = 1; flowers < F; flowers++)
    {
        for (int vazes = 1; vazes <= V; vazes++)
        {
            int num = dp[flowers][vazes];
            for (int k = vazes + 1; k <= V - F + flowers + 1; k++)
            {
                if (num + values[flowers + 1][k] > dp[flowers + 1][k])
                {
                    dp[flowers + 1][k] = num + values[flowers + 1][k];
                    path[flowers + 1][k] = vazes;
                }
            }
        }
    }

    int maxAnswer = INT16_MIN;
    int maxIndex = 0;
    for (int i = 1; i <= V; i++)
    {
        if (dp[F][i] > maxAnswer)
        {
            maxAnswer = dp[F][i];
            maxIndex = i;
        }
    }
    cout << maxAnswer << endl;

    vector<int> answer;
    int num1 = F;
    int num2 = maxIndex;
    // 输出方案
    while (num2)
    {
        answer.push_back(num2);
        num2 = path[num1][num2];
        num1 = num1 - 1;
    }
    for (int i = F - 1; i >= 0; i--)
        cout << answer[i] << " ";
    return 0;
}