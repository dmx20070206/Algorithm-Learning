#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int cats[20];
int condition[20];
int N, W;
int curMin;

void dfs(int firstEmpty, int index)
{
    if (index == N + 1)
    {
        curMin = min(curMin, firstEmpty - 1);
        return;
    }

    if (firstEmpty - 1 >= curMin)
    {
        return;
    }

    for (int i = 1; i <= min(firstEmpty, N); i++)
    {
        if (condition[i] >= cats[index])
        {
            condition[i] -= cats[index];
            if (i == firstEmpty)
                dfs(firstEmpty + 1, index + 1);
            else
                dfs(firstEmpty, index + 1);
            condition[i] += cats[index];
        }
    }
}

int main()
{
    cin >> N >> W;
    curMin = N;
    for (int i = 1; i <= N; i++)
    {
        cin >> cats[i];
        condition[i] = W;
    }

    sort(cats + 1, cats + N + 1, greater<int>());
    dfs(1, 1);
    cout << curMin << endl;
    return 0;
}