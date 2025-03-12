#include <iostream>
#include <vector>
using namespace std;

int f[101];
int main()
{
    int N, V, S;
    cin >> N >> V;
    vector<vector<int>> weights(N + 1, vector<int>{0});
    vector<vector<int>> values(N + 1, vector<int>{0});
    for (int i = 1; i <= N; i++)
    {
        cin >> S;
        for (int j = 0; j < S; j++)
        {
            int weight, value;
            cin >> weight >> value;
            weights[i].push_back(weight);
            values[i].push_back(value);
        }
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = V; j >= 0; j--)
        {
            for (int k = 1; k < weights[i].size(); k++)
            {
                if (j >= weights[i][k])
                    f[j] = max(f[j], f[j - weights[i][k]] + values[i][k]);
            }
        }
    }
    cout << f[V] << endl;
    return 0;
}