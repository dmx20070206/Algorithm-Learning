#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N, M;
int r[25], h[25], minVs[25], minSs[25];
int minS = INT32_MAX;
void dfs(int curFloor, int curV, int curS)
{
    if (curV > N || curS >= minS || (curV == N && curFloor != M + 1))
        return;

    if (curFloor == M + 1)
    {
        minS = curV == N ? min(minS, curS) : minS;
        return;
    }

    // 半径和高度的区间
    int minR = M - curFloor + 1;
    int minH = M - curFloor + 1;
    int maxR = sqrt((N - curV) / minH);
    int maxH = (N - curV) / (minR * minR);
    if (curFloor > 1)
    {
        maxR = min(maxR, r[curFloor - 1] - 1);
        maxH = min(maxH, h[curFloor - 1] - 1);
    }

    // 遍历半径
    for (int _r = maxR; _r >= minR; _r--)
    {
        // 遍历高度
        for (int _h = maxH; _h >= minH; _h--)
        {
            int v = _h * _r * _r;
            int s = curFloor == 1 ? _r * _r + 2 * _r * _h : 2 * _r * _h;

            // 如果是最后一层，必须正好填满
            if (curFloor == M)
            {
                if (curV + v < N)
                    continue;
            }

            // 如果上层蛋糕全部取最小都超界，直接返回
            if (curV + minVs[M - curFloor - 1] > N || curS + minSs[M - curFloor - 1] > minS)
                return;

            // 如果预算出来的最小外表面已经大于答案，直接返回
            if (2 * (N - curV) / _r + curS >= minS)
                return;

            if (N >= curV + v)
            {
                r[curFloor] = _r;
                h[curFloor] = _h;
                dfs(curFloor + 1, curV + v, curS + s);
            }
        }
    }
}

int main()
{
    cin >> N >> M;

    int sumS = 0;
    int sumV = 0;
    for (int i = 1; i <= M; i++)
    {
        minSs[i] = sumS + 2 * i * i;
        minVs[i] = sumV + i * i * i;
        sumS += minSs[i];
        sumV += minVs[i];
    }

    dfs(1, 0, 0);
    if (minS == INT32_MAX)
        cout << 0 << endl;
    else
        cout << minS << endl;
    return 0;
}