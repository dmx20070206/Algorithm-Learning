#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
class Pos
{
public:
    int x;
    int y;
};

Pos monkey;
Pos kuangs[15];
bool visit[15];
int minNum = 0x7f7f7f7f;
int N;

int distance(int x1, int y1, int x2, int y2)
{
    return abs(x1 - x2) + abs(y1 - y2);
}

void dfs(int curNum, int curVisit)
{
    if (curNum >= minNum)
        return;

    if (curVisit == N)
    {
        minNum = min(minNum, curNum);
        return;
    }

    for (int i = 0; i < N; i++)
    {
        if (!visit[i])
        {
            int xx = monkey.x;
            int yy = monkey.y;
            monkey.x = kuangs[i].x;
            monkey.y = kuangs[i].y;
            visit[i] = true;
            dfs(curNum + distance(xx, yy, kuangs[i].x, kuangs[i].y), curVisit + 1);
            visit[i] = false;
            monkey.x = xx;
            monkey.y = yy;
        }
    }
}

int main()
{
    cin >> monkey.x >> monkey.y;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> kuangs[i].x >> kuangs[i].y;
    }
    dfs(0, 0);
    cout << minNum << endl;
    return 0;
}