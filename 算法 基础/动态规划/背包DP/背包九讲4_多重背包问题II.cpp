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
        int k = 1;
        while (num >= k)
        {
            weights.push_back(k * weight);
            values.push_back(k * value);
            num -= k;
            k *= 2;
        }
        if (num > 0)
        {
            weights.push_back(num * weight);
            values.push_back(num * value);
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