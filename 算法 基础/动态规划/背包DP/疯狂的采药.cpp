#include <iostream>
#include <vector>
using namespace std;

const long long M = 1e7 + 5;

long long dp[M];

int main()
{
    long long ItemNum, Capacity;
    cin >> Capacity >> ItemNum;

    vector<long long> weights(ItemNum + 1, 0);
    vector<long long> values(Capacity + 1, 0);
    for (long long i = 1; i <= ItemNum; i++)
    {
        cin >> weights[i] >> values[i];
    }

    for (long long i = 1; i <= ItemNum; i++)
    {
        for (long long j = weights[i]; j <= Capacity; j++)
        {
            dp[j] = max(dp[j], dp[j - weights[i]] + values[i]);
        }
    }
    cout << dp[Capacity] << endl;

    return 0;
}