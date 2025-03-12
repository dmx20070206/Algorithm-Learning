#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <cmath>
using namespace std;
typedef long long ll;

bool if_not_valid(ll i, ll j, ll posX, ll posY)
{
    ll marginX = abs(posX - i);
    ll marginY = abs(posY - j);
    return (marginX && marginY && (marginX + marginY == 3)) || (i == posX && j == posY);
}

int main()
{
    ll sizeX, sizeY;
    cin >> sizeX >> sizeY;
    ll posX, posY;
    cin >> posX >> posY;

    vector<vector<ll>> answer(sizeX + 1, vector<ll>(sizeY + 1, 0));

    for (ll i = 0; i <= sizeX; i++)
    {
        for (ll j = 0; j <= sizeY; j++)
        {
            if (i == 0 && j == 0)
                answer[i][j] = (!if_not_valid(i, j, posX, posY)) ? 1 : 0;
            else if (i == 0)
                answer[i][j] = (!if_not_valid(i, j, posX, posY)) ? answer[i][j - 1] : 0;
            else if (j == 0)
                answer[i][j] = (!if_not_valid(i, j, posX, posY)) ? answer[i - 1][j] : 0;
            else
                answer[i][j] = (!if_not_valid(i, j, posX, posY)) ? answer[i - 1][j] + answer[i][j - 1] : 0;
        }
    }

    cout << answer[sizeX][sizeY];
    return 0;
}