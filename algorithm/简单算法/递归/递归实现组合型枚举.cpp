#include <iostream>
#include <vector>
#include <bitset>
using namespace std;
int n, m;

vector<vector<int>> results;

void backtracking(vector<int> &path, int startIndex)
{
    if (path.size() == m)
    {
        results.push_back(path);
        return;
    }

    for (int i = startIndex; i <= n - m + path.size() + 1; i++)
    {
        path.push_back(i);
        backtracking(path, i + 1);
        path.pop_back();
    }
}

int main()
{
    cin >> n >> m;

    if (m == 0)
    {
        cout << endl;
        return 0;
    }

    vector<int> path;
    backtracking(path, 1);

    for (int i = 0; i < results.size(); i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << results[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}