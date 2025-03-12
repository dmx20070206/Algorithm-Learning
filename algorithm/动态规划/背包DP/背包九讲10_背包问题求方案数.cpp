#include <iostream>
#include <vector>
using namespace std;
#define mod 1000000007
int f[1001];
int nums[1001];
int main()
{
    int N, V;
    cin >> N >> V;
    vector<int> weights(N + 1, 0);
    vector<int> values(N + 1, 0);
    for (int i = 1; i <= N; i++)
    {
        cin >> weights[i] >> values[i];
    }
    for (int i = 0; i <= V; i++)
        nums[i] = 1;

    for (int i = 1; i <= N; i++)
    {
        for (int j = V; j >= 0; j--)
        {
            if (j < weights[i])
                continue;

            if (f[j - weights[i]] + values[i] == f[j])
            {
                nums[j] = (nums[j] + nums[j - weights[i]]) % mod;
            }
            else if (f[j - weights[i]] + values[i] > f[j])
            {
                nums[j] = nums[j - weights[i]];
            }
            f[j] = max(f[j], f[j - weights[i]] + values[i]);
        }
    }
    cout << nums[V] << endl;
    return 0;
}