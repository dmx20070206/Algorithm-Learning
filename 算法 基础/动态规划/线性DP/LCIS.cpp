#include <iostream>
#include <vector>
using namespace std;

int dp[3005][3005];
int main()
{
    int n;
    cin >> n;
    vector<int> A(n + 1, 0);
    vector<int> B(n + 1, 0);

    for (int i = 1; i <= n; i++)
        cin >> A[i];
    for (int i = 1; i <= n; i++)
        cin >> B[i];

    for (int i = 1; i <= n; i++)
    {
        int curMax = 0;
        for (int j = 1; j <= n; j++)
        {
            if (B[j] == A[i])
                dp[i][j] = curMax + 1;
            else
                dp[i][j] = dp[i - 1][j];

            if (B[j] < A[i])
                curMax = max(curMax, dp[i - 1][j]);
        }
    }

    int answer = 1;
    for (int i = 1; i <= n; i++)
        answer = max(answer, dp[n][i]);

    cout << answer << endl;
    return 0;
}