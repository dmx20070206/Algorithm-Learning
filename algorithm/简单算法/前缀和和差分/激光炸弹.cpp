#include <iostream>
#include <string.h>
using namespace std;

int sum[5010][5010];

int main()
{
    int N, R;
    cin >> N >> R;

    if (R == 0)
    {
        cout << 0;
        return 0;
    }

    memset(sum, 0, sizeof sum);

    int max_num = 0;
    for (int i = 0; i < N; i++)
    {
        int X, Y, W;
        cin >> X >> Y >> W;
        max_num = max(max(max_num, X), Y);
        sum[X + 1][Y + 1] += W;
    }
    max_num++;

    for (int i = 1; i <= max_num; i++)
    {
        for (int j = 1; j <= max_num; j++)
        {
            sum[i][j] = sum[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
        }
    }

    if (R >= max_num)
    {
        cout << sum[max_num][max_num];
        return 0;
    }

    int ans = 0;
    for (int i = R; i <= max_num; i++)
    {
        for (int j = R; j <= max_num; j++)
        {
            ans = max(ans, sum[i][j] - sum[i - R][j] - sum[i][j - R] + sum[i - R][j - R]);
        }
    }
    cout << ans << endl;

    return 0;
}