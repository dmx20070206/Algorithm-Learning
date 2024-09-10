#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    vector<int> sons;
    int value;
};
vector<Node> nodes(305);
int N, M;
int f[305][305];
void dp(int index) // 求 f[index][0] -> f[index][M]
{
    f[index][0] = 0;

    // 遍历组别
    for (int i = 0; i < nodes[index].sons.size(); i++)
    {
        // 递归将底层数据准备好
        int sonIndex = nodes[index].sons[i];
        dp(sonIndex);

        // 遍历背包重量
        for (int j = M - 1; j >= 0; j--)
        {
            // 遍历组内物品
            for (int k = 0; k <= j; k++)
            {
                if (k <= j)
                    f[index][j] = max(f[index][j], f[index][j - k] + f[sonIndex][k]);
            }
        }
    }

    if (index != 0)
    {
        for (int i = M; i > 0; i--)
            f[index][i] = f[index][i - 1] + nodes[index].value;
    }
}

int main()
{
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        int pre, value;
        cin >> pre >> value;
        if (pre == 0)
            nodes[0].sons.push_back(i);
        else
            nodes[pre].sons.push_back(i);
        nodes[i].value = value;
    }
    nodes.resize(N + 2);
    dp(0);
    cout << f[0][M] << endl;
    return 0;
}