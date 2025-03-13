#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <functional>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        if (s.size() <= 1)
            return s.size();
        string curStr;
        int maxLength = 0;

        unordered_map<char, int> hash;
        int curBeginIndex = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (hash.find(s[i]) != hash.end())
            {
                curStr.push_back(s[i]);
                int lastIndex = hash[s[i]] - curBeginIndex;
                curBeginIndex = hash[s[i]] + 1;
                for (int j = 0; j <= lastIndex; j++)
                {
                    hash.erase(curStr[j]);
                }
                curStr = curStr.substr(lastIndex + 1, curStr.size() - lastIndex - 1);
            }
            else
            {
                curStr.push_back(s[i]);
            }
            hash[s[i]] = i;
            maxLength = max(maxLength, (int)curStr.size());
        }
        return maxLength;
    }
};