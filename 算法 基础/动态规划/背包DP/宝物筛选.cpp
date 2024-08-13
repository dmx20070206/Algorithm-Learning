#include <iostream>
#include <vector>
using namespace std;
int dp[40005];

int main()
{
    int num, maxWeight;
    cin >> num >> maxWeight;

    vector<int> weights;
    vector<int> values;

    for (int i = 0; i < num; i++)
    {
        int weight, value, number;
        cin >> value >> weight >> number;

        int k = 1;
        while (k <= number)
        {
            weights.push_back(k * weight);
            values.push_back(k * value);
            number -= k;
            k *= 2;
        }
        if (number > 0)
        {
            weights.push_back(number * weight);
            values.push_back(number * value);
        }
    }

    for (int i = 0; i < weights.size(); i++)
        for (int j = maxWeight; j >= weights[i]; j--)
            dp[j] = max(dp[j], dp[j - weights[i]] + values[i]);

    cout << dp[maxWeight] << endl;
    return 0;
}