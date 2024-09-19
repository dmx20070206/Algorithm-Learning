#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
using namespace std;

int sudoku[9][9];
bitset<9> hang[9];
bitset<9> lie[9];
bitset<9> gong[9];

int change(int i, int j)
{
    int num = (i / 3) * 3 + j / 3;
    return num;
}

bool dfs(int curNum)
{
    if (curNum == 81)
    {
        return true;
    }

    int minSel = 9;
    int minI = 0;
    int minJ = 0;
    bool flag = false;
    bitset<9> minSelect;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (sudoku[i][j] != 0)
                continue;
            bitset<9> select;
            select = hang[i] & lie[j] & gong[change(i, j)];
            if (select.count() == 0)
            {
                return false;
            }
            if (minSel >= (int)select.count())
            {
                minSel = select.count();
                minSelect = select;
                minI = i;
                minJ = j;
            }
            if (minSel == 1)
            {
                minI = i;
                minJ = j;
                minSelect = select;
                flag = true;
                break;
            }
        }
        if (flag)
            break;
    }

    int minG = change(minI, minJ);
    for (int i = 0; i < 9; i++)
    {
        if (minSelect[i])
        {
            sudoku[minI][minJ] = i + 1;
            hang[minI][i] = lie[minJ][i] = gong[minG][i] = 0;
            if (dfs(curNum + 1))
            {
                return true;
            }
            sudoku[minI][minJ] = 0;
            hang[minI][i] = lie[minJ][i] = gong[minG][i] = 1;
        }
    }
    return false;
}

int main()
{
    while (true)
    {
        string str;
        cin >> str;
        if (str == "end")
            break;
        int curNum = 0;
        // 输入数独
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (str[i * 9 + j] == '.')
                    sudoku[i][j] = 0;
                else
                {
                    sudoku[i][j] = str[i * 9 + j] - '0';
                    curNum++;
                }
            }
        }

        // 初始化二进制数
        for (int i = 0; i < 9; ++i)
        {
            hang[i].set();
            lie[i].set();
            gong[i].set();
        }
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                int num = sudoku[i][j] - 1;
                if (sudoku[i][j] != 0)
                {
                    hang[i][num] = 0;
                    lie[j][num] = 0;
                    gong[change(i, j)][num] = 0;
                }
            }
        }

        dfs(curNum);
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cout << sudoku[i][j];
            }
        }
        cout << endl;
    }
    return 0;
}