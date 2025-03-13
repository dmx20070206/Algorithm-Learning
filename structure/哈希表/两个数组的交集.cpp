#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, bool> hash;

        for (int i = 0; i < nums1.size(); i++)
        {
            hash[nums1[i]] = true;
        }

        vector<int> answer;
        for (int i = 0; i < nums2.size(); i++)
        {
            if (hash[nums2[i]])
            {
                answer.push_back(nums2[i]);
                hash[nums2[i]] = false;
            }
        }
        return answer;
    }
};