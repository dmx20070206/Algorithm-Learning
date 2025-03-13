#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class MonotonicQueue
{
public:
    deque<int> nums;
    void push(int num)
    {
        while ((int)nums.size() && nums.back() < num)
        {
            nums.pop_back();
        }
        nums.push_back(num);
    }
    void pop(int num)
    {
        if (nums.size() == 0)
            return;
        if (nums.front() == num)
            nums.pop_front();
    }
    int getMax()
    {
        return nums.front();
    }
};

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        MonotonicQueue q;
        vector<int> answer;
        for (int i = 0; i < k; i++)
        {
            q.push(nums[i]);
        }
        for (int i = k; i < nums.size(); i++)
        {
            answer.push_back(q.getMax());
            q.pop(nums[i - k]);
            q.push(nums[i]);
        }
        answer.push_back(q.getMax());
        return answer;
    }
};