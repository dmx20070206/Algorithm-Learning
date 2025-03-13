#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int ans;
bool lights[5][5];

int push(int i, int j)
{
    if (i >= 0 && i < 5 && j >= 0 && j < 5)
    {
        lights[i][j] = !lights[i][j];
        return lights[i][j] ? 1 : -1;
    }
    return 0;
}

void backtracking(int on, int num, int i, int j)
{
    // success
    if (on == 25)
    {
        ans = min(ans, num);
        return;
    }

    // to many num
    if (num >= 6)
        return;

    // out of bandary
    if (i >= 5)
        return;

    // already failed
    if (num >= ans)
        return;
    for (int k = 0; k < i - 1; k++)
    {
        for (int l = 0; l < 5; l++)
        {
            if (!lights[k][l])
                return;
        }
    }

    int next_i = i + (j == 4);
    int next_j = next_i == i ? j + 1 : 0;

    // not put (i, j)
    backtracking(on, num, next_i, next_j);

    // put (i, j)
    on = on + push(i, j) + push(i - 1, j) + push(i + 1, j) + push(i, j + 1) + push(i, j - 1);
    backtracking(on, num + 1, next_i, next_j);
    on = on - push(i, j) + push(i - 1, j) + push(i + 1, j) + push(i, j + 1) + push(i, j - 1);
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int on = 0;
        ans = 0x3f;
        memset(lights, false, sizeof lights);

        for (int i = 0; i < 5; i++)
        {
            string str;
            cin >> str;
            for (int j = 0; j < 5; j++)
            {
                if (str[j] == '1')
                {
                    on++;
                    lights[i][j] = true;
                }
            }
        }

        backtracking(on, 0, 0, 0);
        cout << (0x3f == ans ? -1 : ans) << endl;
    }
    return 0;
}