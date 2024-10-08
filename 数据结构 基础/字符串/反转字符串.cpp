#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        if (s.size() <= 1)
            return;

        int right = s.size() - 1;
        int left = 0;
        while (left < right)
        {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
};