#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int duplicateInArray(vector<int> nums)
    {
        unordered_map<int, int> hash;
        bool flag = false;
        int answer = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (hash[nums[i]])
            {
                flag = true;
                answer = nums[i];
            }
            if (!flag && nums[i] < nums.size())
                hash[nums[i]]++;
            if (nums[i] >= nums.size())
                return -1;
        }
        return flag ? answer : -1;
    }
};