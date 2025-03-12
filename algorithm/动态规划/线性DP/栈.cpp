#include <iostream>
using namespace std;
typedef long long ll;
ll dp[20][20];

ll dfs(int i, int j)
{
    if (dp[i][j])
        return dp[i][j];
    if (i == 0)
        return dp[i][j] = 1;
    if (j == 0)
        return dp[i][j] = dfs(i - 1, j + 1);
    return dp[i][j] = dfs(i - 1, j + 1) + dfs(i, j - 1);
}

int main()
{
    int n;
    cin >> n;
    cout << dfs(n, 0) << endl;
    return 0;
}