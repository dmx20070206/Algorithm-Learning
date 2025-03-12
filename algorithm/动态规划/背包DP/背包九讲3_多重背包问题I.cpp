#include <iostream>
#include <vector>
using namespace std;

int f[10001];
int main()
{
    int N, V;
    cin >> N >> V;
    vector<int> weights;
    vector<int> values;
    for (int i = 0; i < N; i++)
    {
        int weight, value, num;
        cin >> weight >> value >> num;
        for (int j = 1; j <= num; j++)
        {
            weights.push_back(weight);
            values.push_back(value);
        }
    }

    for (int i = 0; i < weights.size(); i++)
    {
        for (int j = V; j >= weights[i]; j--)
        {
            f[j] = max(f[j], f[j - weights[i]] + values[i]);
        }
    }
    cout << f[V] << endl;
    return 0;
}