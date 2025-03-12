#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

class Compare
{
public:
    bool operator()(vector<int> &v1, vector<int> &v2)
    {
        return v1[0] < v2[0];
    }
};

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), Compare());
        vector<vector<int>> answer;

        int curLeft = intervals[0][0];
        int curRight = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++)
        {
            if (curRight < intervals[i][0])
            {
                answer.push_back(vector<int>{curLeft, curRight});
                curLeft = intervals[i][0];
                curRight = intervals[i][1];
            }
            else
            {
                curRight = max(curRight, intervals[i][1]);
            }
        }
        answer.push_back(vector<int>{curLeft, curRight});
        return answer;
    }
};