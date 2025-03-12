#include <iostream>
#include <vector>
using namespace std;
class Node
{
public:
    int val;
    vector<int> sons;
    bool hasFather;
    Node()
    {
        hasFather = false;
    }
};

int f[6005][2];
vector<Node> nodes;
void dp(int index)
{
    f[index][0] = 0;
    f[index][1] = nodes[index].val;

    for (int i = 0; i < nodes[index].sons.size(); i++)
    {
        int sonIndex = nodes[index].sons[i];
        dp(sonIndex);
        f[index][0] += max(f[sonIndex][0], f[sonIndex][1]);
        f[index][1] += f[sonIndex][0];
    }
}

int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        nodes.push_back(Node());
        cin >> nodes[i].val;
    }
    for (int i = 1; i < N; i++)
    {
        int num1, num2;
        cin >> num1 >> num2;
        num1--;
        num2--;
        nodes[num1].hasFather = true;
        nodes[num2].sons.push_back(num1);
    }

    int root = -1;
    for (int i = 0; i < nodes.size(); i++)
    {
        if (!nodes[i].hasFather)
        {
            root = i;
            break;
        }
    }
    dp(root);
    cout << max(f[root][0], f[root][1]) << endl;
    return 0;
}