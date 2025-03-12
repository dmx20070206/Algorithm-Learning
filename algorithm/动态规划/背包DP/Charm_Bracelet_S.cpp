#include <iostream>
#include <vector>
using namespace std;
int dp[12890];

int main()
{
    int ItemNum, Capacity;
    cin >> ItemNum >> Capacity;

    vector<int> weights(ItemNum + 1, 0);
    vector<int> values(Capacity + 1, 0);
    for (int i = 1; i <= ItemNum; i++)
    {
        cin >> weights[i] >> values[i];
    }

    for (int i = 1; i <= ItemNum; i++)
    {
        for (int j = Capacity; j >= weights[i]; j--)
        {
            dp[j] = max(dp[j], dp[j - weights[i]] + values[i]);
        }
    }
    cout << dp[Capacity] << endl;

    return 0;
}