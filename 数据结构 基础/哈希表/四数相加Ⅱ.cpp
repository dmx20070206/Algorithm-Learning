#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
    {
        int answer = 0;
        unordered_map<int, int> hash;
        for (int i : nums1)
        {
            for (int j : nums2)
            {
                hash[i + j]++;
            }
        }

        for (int k : nums3)
        {
            for (int l : nums4)
            {
                if (hash[-(k + l)])
                    answer += hash[-(k + l)];
            }
        }
        return answer;
    }
};