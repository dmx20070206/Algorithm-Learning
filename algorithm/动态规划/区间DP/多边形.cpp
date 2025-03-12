#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

void SetEraseNum(vector<int> &points, vector<char> &edges, int num)
{
    // 删除第 i 条边 => 以第 i 个点为起点
    // 数组整体左移 i - 1 位
    int tmp = points[1];
    for (int i = 1; i < points.size() - 1; i++)
    {
        points[i] = points[i + 1];
    }
    points[points.size() - 1] = tmp;

    tmp = edges[1];
    for (int i = 1; i < edges.size() - 1; i++)
    {
        edges[i] = edges[i + 1];
    }
    edges[edges.size() - 1] = tmp;
}

vector<int> MINMAX(int a, int b, int c, int d)
{
    vector<int> arr{a, b, c, d};
    sort(arr.begin(), arr.end());
    return {arr[0], arr[3]};
}

int dp[51][51][2];
int main()
{
    int N;
    cin >> N;

    // points[1] ~ points[N] : 1 ~ N 个点的权值
    // edges[1]  ~ edges[N]  : 1 ~ N 个边的权值 第 i 条边代表第 i-1 个点和第 i 个点的边
    vector<int> points(N + 1, 0);
    vector<char> edges(N + 1, ' ');
    for (int i = 1; i <= N; i++)
    {
        cin >> edges[i];
        cin >> points[i];
    }

    vector<int> answer;
    int finalNum = -0x3f3f3f3f;
    for (int eraseEdge = 1; eraseEdge <= N; eraseEdge++) // 枚举删除的边
    {
        // 处理数组
        if (eraseEdge > 1)
            SetEraseNum(points, edges, 1);

        // 初始化 dp 数组
        memset(dp, 0, sizeof dp);
        for (int i = 1; i <= N; i++)
            dp[i][i][0] = dp[i][i][1] = points[i];

        for (int len = 2; len <= N; len++) // 阶段
        {
            for (int left = 1; left <= N + 1 - len; left++) // 状态
            {
                int right = len + left - 1;

                // 决策合集
                for (int k = left; k < right; k++)
                {
                    char ops = edges[k + 1];
                    if (ops == 't') // +
                    {
                        // min
                        int minNum = dp[left][k][0] + dp[k + 1][right][0];
                        dp[left][right][0] = k == left ? minNum : min(dp[left][right][0], minNum);

                        // max
                        int maxNum = dp[left][k][1] + dp[k + 1][right][1];
                        dp[left][right][1] = k == left ? maxNum : max(dp[left][right][1], maxNum);
                    }

                    if (ops == 'x') // x
                    {
                        int min_min = dp[left][k][0] * dp[k + 1][right][0];
                        int min_max = dp[left][k][0] * dp[k + 1][right][1];
                        int max_min = dp[left][k][1] * dp[k + 1][right][0];
                        int max_max = dp[left][k][1] * dp[k + 1][right][1];

                        int minNum = MINMAX(min_min, min_max, max_min, max_max)[0];
                        int maxNum = MINMAX(min_min, min_max, max_min, max_max)[1];
                        dp[left][right][0] = k == left ? minNum : min(dp[left][right][0], minNum);
                        dp[left][right][1] = k == left ? maxNum : max(dp[left][right][1], maxNum);
                    }
                }
            }
        }
        answer.push_back(dp[1][N][1]);
        finalNum = max(finalNum, dp[1][N][1]);
    }

    cout << finalNum << endl;
    for (int i = 0; i < answer.size(); i++)
    {
        if (answer[i] == finalNum)
            cout << i + 1 << " ";
    }
    return 0;
}