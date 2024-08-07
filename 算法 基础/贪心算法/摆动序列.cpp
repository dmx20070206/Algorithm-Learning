// https://leetcode.cn/problems/wiggle-subsequence/description/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int wiggleMaxLength(vector<int> &nums)
    {
        if (nums.size() <= 1)
            return nums.size();

        int answer = 0;
        int lastDiff = 0;
        int curDiff = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            curDiff = nums[i] - nums[i + 1];
            if ((curDiff > 0 && lastDiff <= 0) || (curDiff < 0 && lastDiff >= 0))
            {
                answer++;
                lastDiff = curDiff;
            }
        }

        return ++answer;
    }
};
