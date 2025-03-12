#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

int lens[64], use[64];
int N, len, sum, cnt, maxN;

bool dfs(int curStick, int curNum, int lastIndex)
{
    if (curStick > cnt)
        return true;

    if (curNum == len)
        return dfs(curStick + 1, 0, 0);

    int fail = 0;
    for (int i = lastIndex; i < N; i++)
    {
        if (lens[i] + curNum <= len && !use[i] && fail != lens[i])
        {
            use[i] = 1;
            if (dfs(curStick, curNum + lens[i], i + 1))
                return true;
            fail = lens[i];
            use[i] = 0;
            if (curNum == 0)
                return false;
            if (curNum + lens[i] == len)
                return false;
        }
    }
    return false;
}

int main()
{
    while (true)
    {
        cin >> N;
        sum = 0;
        maxN = 0;
        if (N == 0)
            break;
        for (int i = 0; i < N; i++)
        {
            cin >> lens[i];
            sum += lens[i];
            maxN = max(maxN, lens[i]);
        }
        sort(lens, lens + N, greater<int>());
        for (len = maxN; len <= sum; len++)
        {
            if (sum % len)
                continue;
            cnt = sum / len;
            memset(use, 0, sizeof use);
            if (dfs(1, 0, 0))
                break;
        }
        cout << len << endl;
    }
    return 0;
}