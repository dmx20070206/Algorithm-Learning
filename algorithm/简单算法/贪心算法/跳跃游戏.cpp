// https://leetcode.cn/problems/jump-game/description/

#include <iostream>
#include <vector>
#include <functional>
using namespace std;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        if (nums.size() <= 1)
            return true;

        int cover = 0;
        for (int i = 0; i <= cover; i++)
        {
            cover = max(cover, i + nums[i]);
            if (cover >= nums.size() - 1)
                return true;
        }
        return false;
    }
};