#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> GenerateNextArray(string str)
    {
        int size = str.size();
        vector<int> next(size, 0);

        int curNum = 0;
        for (int i = 1; i < size;)
        {
            if (str[curNum] == str[i])
            {
                curNum++;
                next[i] = curNum;
                i++;
            }
            else
            {
                if (curNum == 0)
                {
                    next[i] = 0;
                    i++;
                }
                else
                    curNum = next[curNum - 1];
            }
        }
        return next;
    }

    int strStr(string haystack, string needle)
    {
        vector<int> next = GenerateNextArray(needle);

        int index = 0;
        int pos = 0;
        while (index < haystack.size())
        {
            if (needle[pos] == haystack[index])
            {
                pos++;
                index++;
            }
            else if (pos != 0)
            {
                pos = next[pos - 1];
            }
            else
            {
                index++;
            }

            if (pos == needle.size())
                return index - pos;
        }
        return -1;
    }
};