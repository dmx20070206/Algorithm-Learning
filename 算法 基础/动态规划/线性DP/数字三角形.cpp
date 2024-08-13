#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;

int main()
{
    int num;
    cin >> num;
    vector<vector<int>> arr(num, vector<int>(num, 0));
    vector<vector<int>> answer(num, vector<int>(num, 0));
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cin >> arr[i][j];
        }
    }

    answer[0][0] = arr[0][0];
    for (int i = 1; i < num; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (j == 0)
                answer[i][j] = answer[i - 1][j] + arr[i][j];
            else
                answer[i][j] = max(answer[i - 1][j - 1], answer[i - 1][j]) + arr[i][j];
        }
    }

    int maxNum = INT16_MIN;
    for (int i = 0; i < num; i++)
    {
        maxNum = max(maxNum, answer[num - 1][i]);
    }

    cout << maxNum << endl;
    return 0;
}