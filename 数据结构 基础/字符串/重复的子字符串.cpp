#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    bool repeatedSubstringPattern(string s)
    {
        if (s.size() <= 1)
            return false;

        int size = s.size();
        vector<int> next(size, 0);

        int index = 1;
        int curNum = 0;
        while (index < size)
        {
            if (s[curNum] == s[index])
            {
                next[index] = ++curNum;
                index++;
            }
            else
            {
                if (curNum == 0)
                {
                    next[index] = 0;
                    index++;
                }
                else
                {
                    curNum = next[curNum - 1];
                }
            }
        }

        return next[size - 1] && !(size % (size - next[size - 1]));
    }
};