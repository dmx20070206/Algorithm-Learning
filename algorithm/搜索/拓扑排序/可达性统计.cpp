#include <iostream>
#include <vector>
#include <queue>
#include <bitset>
using namespace std;

#define MaxM 30001
int ver[MaxM], head[MaxM], nexts[MaxM], deg[MaxM], nums[MaxM];
bitset<MaxM> f[MaxM];

int num = 0;
void addEdge(int a, int b)
{
    ver[++num] = b;
    nexts[num] = head[a];
    head[a] = num;
    deg[b]++;
}
int main()
{
    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= M; i++)
    {
        int a, b;
        cin >> a >> b;
        addEdge(a, b);
    }

    // 拓扑排序
    vector<int> arrange;
    queue<int> q;
    for (int i = 1; i <= M; i++)
        if (deg[i] == 0)
            q.push(i);

    while (!q.empty())
    {
        int index = q.front();
        arrange.push_back(index);
        q.pop();
        for (int i = head[index]; i; i = nexts[i])
        {
            int dst = ver[i];
            deg[dst]--;
            if (deg[dst] == 0)
                q.push(dst);
        }
    }

    // 倒序遍历
    for (int i = M - 1; i >= 0; i--)
    {
        int index = arrange[i];
        f[index][index] = 1;
        for (int j = head[index]; j; j = nexts[j])
        {
            int dst = ver[j];
            f[index] |= f[dst];
        }
    }

    for (int i = 1; i <= N; i++)
    {
        cout << f[i].count() << endl;
    }

    return 0;
}