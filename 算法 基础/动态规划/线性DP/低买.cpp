#include <iostream>
#include <vector>
#include <unordered_set>
#include <string.h>
using namespace std;

int dp[5005];

int main()
{
    int N;
    cin >> N;
    vector<int> price(N + 1, 0);
    vector<int> ideas(N + 1, 0);

    for (int i = 1; i <= N; i++)
        cin >> price[i];

    for (int i = 1; i <= N; i++)
    {
        dp[i] = 1;
        for (int j = 1; j < i; j++)
        {
            if (price[i] < price[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        for (int j = 1; j < i; j++)
        {
            if (price[i] == price[j] && dp[i] == dp[j])
            {
                // ideas[i] = max(ideas[i], ideas[j]);
                ideas[j] = 0;
            }
            if (price[i] < price[j] && dp[i] == dp[j] + 1)
            {
                ideas[i] += ideas[j];
            }
        }
        if (dp[i] == 1)
            ideas[i] = 1;
    }

    int answer = 0;
    for (int i = 1; i <= N; i++)
        answer = max(answer, dp[i]);

    int idea = 0;
    for (int i = 1; i <= N; i++)
    {
        if (answer == dp[i])
            idea += ideas[i];
    }
    cout << answer << " " << idea << endl;

    return 0;
}