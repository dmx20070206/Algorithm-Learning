// https://leetcode.cn/problems/jump-game-ii/description/

#include <iostream>
#include <vector>
#include <functional>
using namespace std;

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        if (nums.size() <= 1)
            return 0;
        int curPos = 0;
        int nextPos = 0;
        int time = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            nextPos = max(nextPos, nums[i] + i);
            if (i == curPos)
            {
                time++;
                curPos = nextPos;
            }
        }
        return time;
    }
};