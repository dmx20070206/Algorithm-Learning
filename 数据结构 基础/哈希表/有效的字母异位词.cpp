#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
            return false;

        unordered_map<char, int> hash;
        for (int i = 0; i < s.size(); i++)
        {
            hash[s[i]]++;
        }
        for (int i = 0; i < t.size(); i++)
        {
            hash[t[i]]--;
            if (hash[t[i]] < 0)
                return false;
        }
        return true;
    }
};