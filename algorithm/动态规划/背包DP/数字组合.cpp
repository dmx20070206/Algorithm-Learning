#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

int dp[10001];
int main()
{
    int N, M;
    cin >> N >> M;

    vector<int> nums(N + 1, 0);
    for (int i = 1; i <= N; i++)
        cin >> nums[i];

    dp[0] = 1;
    for (int i = 1; i <= N; i++)
    {
        for (int j = M; j >= nums[i]; j--)
        {
            dp[j] += dp[j - nums[i]];
        }
    }
    cout << dp[M] << endl;
    return 0;
}