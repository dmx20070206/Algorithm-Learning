#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int dp[40][40][40][40];

int main()
{
    memset(dp, -0x3f, sizeof dp);
    int N, M;
    cin >> N >> M;
    vector<int> scores(N + 1, 0);
    for (int i = 1; i <= N; i++)
    {
        cin >> scores[i];
    }
    int nums[5] = {-1, 0, 0, 0, 0};
    for (int i = 0; i < M; i++)
    {
        int num;
        cin >> num;
        nums[num]++;
    }

    dp[nums[1]][nums[2]][nums[3]][nums[4]] = scores[1];
    for (int i1 = nums[1]; i1 >= 0; i1--)
    {
        for (int i2 = nums[2]; i2 >= 0; i2--)
        {
            for (int i3 = nums[3]; i3 >= 0; i3--)
            {
                for (int i4 = nums[4]; i4 >= 0; i4--)
                {
                    int curPos = (nums[1] - i1) + 2 * (nums[2] - i2) + 3 * (nums[3] - i3) + 4 * (nums[4] - i4) + 1;
                    int num = dp[i1][i2][i3][i4];
                    if (i1 >= 1)
                        dp[i1 - 1][i2][i3][i4] = max(dp[i1 - 1][i2][i3][i4], num + scores[curPos + 1]);
                    if (i2 >= 1)
                        dp[i1][i2 - 1][i3][i4] = max(dp[i1][i2 - 1][i3][i4], num + scores[curPos + 2]);
                    if (i3 >= 1)
                        dp[i1][i2][i3 - 1][i4] = max(dp[i1][i2][i3 - 1][i4], num + scores[curPos + 3]);
                    if (i4 >= 1)
                        dp[i1][i2][i3][i4 - 1] = max(dp[i1][i2][i3][i4 - 1], num + scores[curPos + 4]);
                }
            }
        }
    }
    cout << dp[0][0][0][0] << endl;
    return 0;
}