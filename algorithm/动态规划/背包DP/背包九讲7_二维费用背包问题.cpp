#include <iostream>
#include <vector>
using namespace std;

int f[101][101];
int main()
{
    int N, V, M;
    cin >> N >> V >> M;
    vector<int> weights(N + 1, 0);
    vector<int> values(N + 1, 0);
    vector<int> volumns(N + 1, 0);

    for (int i = 1; i <= N; i++)
    {
        cin >> volumns[i] >> weights[i] >> values[i];
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = V; j >= volumns[i]; j--)
        {
            for (int k = M; k >= weights[i]; k--)
            {
                f[j][k] = max(f[j][k], f[j - volumns[i]][k - weights[i]] + values[i]);
            }
        }
    }
    cout << f[V][M] << endl;
    return 0;
}