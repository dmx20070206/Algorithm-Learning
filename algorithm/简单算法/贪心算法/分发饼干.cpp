// https://leetcode.cn/problems/assign-cookies/
// 注意遍历顺序和对象，省去双重循环

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int answer = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (answer < g.size() && g[answer] <= s[i])
                answer++;
            if (answer >= g.size())
                break;
        }

        return answer;
    }
};