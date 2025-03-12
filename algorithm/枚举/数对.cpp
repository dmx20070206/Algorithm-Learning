// 一个数组中的数互不相同，求其中和为 0 的数对的个数。

#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

#define MAXNUM 1000

int main()
{
    int n;
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        nums.push_back(num);
    }

    bool upMemory[MAXNUM];
    bool downMemory[MAXNUM];
    memset(upMemory, 0, sizeof(upMemory));
    memset(downMemory, 0, sizeof(downMemory));

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] > 0)
        {
            if (downMemory[nums[i] - 1])
                sum++;
            upMemory[nums[i] - 1] = true;
        }

        if (nums[i] < 0)
        {
            if (upMemory[-nums[i] - 1])
                sum++;
            downMemory[-nums[i] - 1] = true;
        }
    }
    cout << sum << endl;
    return 0;
}