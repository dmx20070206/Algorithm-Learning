#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits.h>
using namespace std;
typedef long long ll;

ll dp[2024][2024];
int main()
{
    ll n;
    cin >> n;
    vector<int> nums(n, 0);
    int maxNum = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> nums[i];
        maxNum = max(maxNum, nums[i]);
    }

    // 离散化
    // vector<ll> tmp(nums);
    // sort(tmp.begin(), tmp.end());
    // tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
    // for (ll i = 0; i < n; i++)
    //     nums[i] = lower_bound(tmp.begin(), tmp.end(), nums[i]) - tmp.begin();

    // 递增
    for (ll i = 1; i <= n; i++)
    {
        ll val = dp[i - 1][0];
        for (ll j = 0; j <= maxNum; j++)
        {
            val = min(val, dp[i - 1][j]);
            dp[i][j] = val;
            dp[i][j] += j > nums[i - 1] ? j - nums[i - 1] : nums[i - 1] - j;
        }
    }

    ll answer1 = dp[n][0];
    for (ll i = 0; i <= n; i++)
        answer1 = min(answer1, dp[n][i]);

    // 递减
    for (ll i = 1; i <= n; i++)
    {
        ll val = dp[i - 1][0];
        for (ll j = maxNum; j >= 0; j--)
        {
            val = min(val, dp[i - 1][j]);
            dp[i][j] = val;
            dp[i][j] += j > nums[i - 1] ? j - nums[i - 1] : nums[i - 1] - j;
        }
    }

    ll answer2 = dp[n][0];
    for (ll i = 0; i <= maxNum; i++)
        answer2 = min(answer2, dp[n][i]);

    // answer
    cout << min(answer1, answer2) << endl;

    return 0;
}