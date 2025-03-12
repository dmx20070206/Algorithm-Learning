#include <iostream>
#include <vector>
using namespace std;

int dp[10005];
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    int answer = 1;
    dp[0] = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[i] > nums[j])
                dp[i] = max(dp[i], dp[j] + 1);
        }
        dp[i] = max(dp[i], 1);
        answer = max(answer, dp[i]);
    }
    cout << answer << endl;
    return 0;
}