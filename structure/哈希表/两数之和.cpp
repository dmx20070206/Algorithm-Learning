#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); i++)
        {
            if (hash[target - nums[i]])
                return {i, hash[target - nums[i]] - 1};
            hash[nums[i]] = i + 1;
        }
        return vector<int>();
    }
};