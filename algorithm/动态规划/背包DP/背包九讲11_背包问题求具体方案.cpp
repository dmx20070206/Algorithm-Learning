#include <iostream>
#include <vector>
using namespace std;

// f[i][j]: 第 i ~ N 个物品，背包容量为 j
int f[1005][1005];
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

    for (int i = N; i > 0; i--)
    {
        for (int j = 0; j <= V; j++)
        {
            if (j >= weights[i])
                f[i][j] = max(f[i + 1][j], f[i + 1][j - weights[i]] + values[i]);
            else
                f[i][j] = f[i + 1][j];
        }
    }

    vector<int> conditions(N + 1, 0);
    int curN = 1;
    int curV = V;
    while (curN <= N)
    {
        // 必须选 curN 物品
        if (curV >= weights[curN] && f[curN][curV] == f[curN + 1][curV - weights[curN]] + values[curN])
        {
            conditions[curN] = 1;
            curV -= weights[curN];
        }
        // 不选 curN 物品
        else if (f[curN][curV] == f[curN + 1][curV])
        {
            conditions[curN] = 0;
        }
        curN++;
    }
    for (int i = 1; i <= N; i++)
        if (conditions[i])
            cout << i << " ";
    return 0;
}