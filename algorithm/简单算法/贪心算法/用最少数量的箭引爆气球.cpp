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
    int findMinArrowShots(vector<vector<int>> &points)
    {
        cin.tie(0);
        sort(points.begin(), points.end(), Compare());

        int maxCurRightPos = points[0][1];
        int answer = 0;
        for (int i = 1; i < points.size(); i++)
        {
            if (maxCurRightPos < points[i][0])
            {
                answer++;
                maxCurRightPos = points[i][1];
            }
            else
                maxCurRightPos = min(maxCurRightPos, points[i][1]);
        }
        return answer + 1;
    }
};