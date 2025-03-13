#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

int n;
vector<vector<int>> results;

void backtracking(vector<int> &path, bitset<10> &used)
{
    if (path.size() == n)
    {
        results.push_back(path);
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (used[i])
            continue;
        path.push_back(i);
        used[i] = 1;
        backtracking(path, used);
        used[i] = 0;
        path.pop_back();
    }
}

int main()
{
    cin >> n;

    vector<int> path;
    bitset<10> bit;

    backtracking(path, bit);

    for (int i = 0; i < results.size(); i++)
    {
        for (int j = 0; j < results[i].size(); j++)
        {
            cout << results[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}