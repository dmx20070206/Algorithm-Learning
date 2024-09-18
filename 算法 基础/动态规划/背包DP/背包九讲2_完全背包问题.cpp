#include <iostream>
#include <vector>
using namespace std;

int f[1001];
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

    for (int i = 1; i <= N; i++)
    {
        for (int j = weights[i]; j <= V; j++)
        {
            f[j] = max(f[j], f[j - weights[i]] + values[i]);
        }
    }
    cout << f[V] << endl;
    return 0;
}