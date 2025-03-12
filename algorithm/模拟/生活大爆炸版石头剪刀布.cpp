// https://uoj.ac/problem/15

#include <iostream>
#include <vector>
using namespace std;

// 1 - win, 0 - draw, -1 - lose
int who_win(int i, int j)
{
    int flag = 1;
    if (i > j)
    {
        swap(i, j);
        flag = -1;
    }
    int num = i * 10 + j;
    switch (num)
    {
    case (00):
        return flag * 0;
    case (01):
        return flag * -1;
    case (02):
        return flag * 1;
    case (03):
        return flag * 1;
    case (04):
        return flag * -1;
    case (11):
        return flag * 0;
    case (12):
        return flag * -1;
    case (13):
        return flag * 1;
    case (14):
        return flag * -1;
    case (22):
        return flag * 0;
    case (23):
        return flag * -1;
    case (24):
        return flag * 1;
    case (33):
        return flag * 0;
    case (34):
        return flag * 1;
    case (44):
        return flag * 0;
    }
    return 0;
}

int main()
{
    int TotalTime, A, B;
    cin >> TotalTime >> A >> B;

    vector<int> strategyA, strategyB;
    for (int i = 0; i < A; i++)
    {
        int num;
        cin >> num;
        strategyA.push_back(num);
    }
    for (int i = 0; i < B; i++)
    {
        int num;
        cin >> num;
        strategyB.push_back(num);
    }

    int scoreA = 0, scoreB = 0;
    int first = 0, second = 0;
    for (int i = 0; i < TotalTime; i++)
    {
        if (who_win(strategyA[first], strategyB[second]) == 1)
        {
            scoreA++;
        }
        else if (who_win(strategyA[first], strategyB[second]) == -1)
        {
            scoreB++;
        }
        first = (first + 1) % A;
        second = (second + 1) % B;
    }
    cout << scoreA << " " << scoreB << endl;
    return 0;
}