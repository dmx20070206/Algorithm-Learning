// https://leetcode.cn/problems/maximum-subarray/description/

#include <iostream>
#include <vector>
#include <functional>
using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        if (nums.size() == 1)
            return nums[0];

        int answer = INT32_MIN;
        int curSum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            curSum += nums[i];
            answer = max(answer, curSum);
            if (curSum < 0)
            {
                curSum = 0;
            }
        }
        return answer;
    }
};