#include <iostream>
#include <vector>
using namespace std;

class Item
{
public:
    int value;
    int weight;
    Item(int w, int v)
    {
        this->value = v;
        this->weight = w;
    }
};
int dp[1005];

int main()
{
    int n, m;
    cin >> m >> n;
    int num = 0;
    vector<vector<Item>> items(n, vector<Item>());
    for (int i = 0; i < n; i++)
    {
        int weight;
        int value;
        int number;
        cin >> weight >> value >> number;
        num = max(num, number - 1);
        items[number - 1].push_back(Item(weight, value));
    }
    items.resize(num + 1);

    for (int i = 0; i < items.size(); i++)
    {
        for (int j = m; j >= 0; j--)
        {
            for (int k = 0; k < items[i].size(); k++)
            {
                if (j >= items[i][k].weight)
                    dp[j] = max(dp[j], dp[j - items[i][k].weight] + items[i][k].value);
            }
        }
    }

    cout << dp[m] << endl;

    return 0;
}