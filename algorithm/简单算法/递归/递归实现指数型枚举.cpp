#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

vector<vector<int>> results;
int n;

void backtracking(vector<int> &path, int startIndex)
{
    results.push_back(path);

    for (int i = startIndex; i <= n; i++)
    {
        path.push_back(i);
        backtracking(path, i + 1);
        path.pop_back();
    }
}

int main()
{
    cin >> n;
    vector<int> path;
    backtracking(path, 1);

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