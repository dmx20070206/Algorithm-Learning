#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int weight;
    int value;
    vector<int> sons;
};

// 第 i 个节点选，并且给子树分配 j 个容量的最大价值
int f[101][101];
vector<Node> nodes(101, Node());
int N, V;

void dfs(int index)
{
    // 分组背包外层循环：遍历分组
    for (int i = 0; i < nodes[index].sons.size(); i++)
    {
        // 通过递归求解子树问题
        int son = nodes[index].sons[i];
        dfs(son);

        // 分组背包中层循环：遍历背包容量
        for (int j = V; j >= 0; j--)
        {
            // 分组背包内层循环：遍历组内物品
            for (int k = 0; k <= j; k++)
            {
                // 第 k 个物品对应的重量和价值（k从0开始）
                int weight = k;
                int value = f[son][k];
                f[index][j] = max(f[index][j], f[index][j - weight] + value);
            }
        }
    }

    // 必须选择父节点
    for (int j = V; j >= nodes[index].weight; j--)
        f[index][j] = nodes[index].value + f[index][j - nodes[index].weight];

    // 处理非法节点
    for (int j = 0; j < nodes[index].weight; j++)
        f[index][j] = 0;
}

int main()
{
    cin >> N >> V;
    int root = -1;
    nodes.resize(N + 1);
    for (int i = 1; i <= N; i++)
    {
        int num;
        cin >> nodes[i].weight >> nodes[i].value >> num;
        if (num != -1)
            nodes[num].sons.push_back(i);
        root = num == -1 ? i : root;
    }
    dfs(root);
    cout << f[root][V] << endl;
    return 0;
}