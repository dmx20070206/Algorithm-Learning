// https://leetcode.cn/problems/candy/description/

#include <iostream>
#include <vector>
#include <functional>
using namespace std;

class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        int size = ratings.size();
        vector<int> levels_left(size, 1);
        vector<int> levels_right(size, 1);
        for (int i = 1; i < levels_left.size(); i++)
        {
            if (ratings[i] > ratings[i - 1])
            {
                levels_left[i] = levels_left[i - 1] + 1;
            }
        }
        for (int i = levels_right.size() - 1; i > 0; i--)
        {
            if (ratings[i - 1] > ratings[i])
            {
                levels_right[i - 1] = levels_right[i] + 1;
            }
        }
        int sum = 0;
        for (int i = 0; i < size; i++)
        {
            sum += max(levels_left[i], levels_right[i]);
        }
        return sum;
    }
};