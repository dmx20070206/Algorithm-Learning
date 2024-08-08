#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    string reverseStr(string s, int k)
    {
        int curPos = 0;
        int endPos = 0;
        bool flag = true;
        while (endPos != s.size())
        {
            endPos = min(curPos + k, (int)s.size());
            if (flag == true)
            {
                reverse(s.begin() + curPos, s.begin() + endPos);
            }
            flag = !flag;
            curPos += k;
        }
        return s;
    }
};