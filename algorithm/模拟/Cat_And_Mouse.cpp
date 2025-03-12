#include <iostream>
#include <vector>
using namespace std;

int map[12][12];
class Mouse
{
public:
    int posX;
    int posY;
    pair<int, int> dir;
    void Move()
    {
        if (map[posX + dir.first][posY + dir.second])
        {
            posX += dir.first;
            posY += dir.second;
        }
        else
        {
            int temp1 = dir.first;
            int temp2 = dir.second;
            dir.first = temp1 == 0 ? temp2 : 0;
            dir.second = temp2 == 0 ? -temp1 : 0;
        }
    }
};
class Cat
{
public:
    int posX;
    int posY;
    pair<int, int> dir;
    void Move()
    {
        if (map[posX + dir.first][posY + dir.second])
        {
            posX += dir.first;
            posY += dir.second;
        }
        else
        {
            int temp1 = dir.first;
            int temp2 = dir.second;
            dir.first = temp1 == 0 ? temp2 : 0;
            dir.second = temp2 == 0 ? -temp1 : 0;
        }
    }
};
int main()
{
    Mouse m;
    Cat c;
    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
            char s;
            cin >> s;
            if (s == '*')
            {
                map[i][j] = 0;
            }
            else if (s == '.')
            {
                map[i][j] = 1;
            }
            else if (s == 'C')
            {
                map[i][j] = 1;
                c.posX = i;
                c.posY = j;
                c.dir = {-1, 0};
            }
            else if (s == 'M')
            {
                map[i][j] = 1;
                m.posX = i;
                m.posY = j;
                m.dir = {-1, 0};
            }
        }
    }
    int num = 0;
    while (true)
    {
        num++;
        c.Move();
        m.Move();
        if (c.posX == m.posX && c.posY == m.posY)
        {
            break;
        }
    }
    cout << num << endl;
    return 0;
}

// *...*.....
// ......*...
// ...*...*..
// ..........
// ...*.C....
// *.....*...
// ...*......
// ..M......*
// ...*.*....
// .*.*......