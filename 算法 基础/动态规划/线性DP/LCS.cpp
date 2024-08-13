#include <iostream>
#include <vector>
using namespace std;

int dp[10005][10005];
int main()
{
    int n;
    cin >> n;
    vector<int> arr1(n + 1, 0);
    vector<int> arr2(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> arr1[i];
    for (int i = 1; i <= n; i++)
        cin >> arr2[i];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (arr1[i] == arr2[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            dp[i][j] = max(dp[i][j], max(dp[i - 1][j], dp[i][j - 1]));
        }
    }
    cout << dp[n][n] << endl;
    return 0;
}