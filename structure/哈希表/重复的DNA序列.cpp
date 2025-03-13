#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<string> findRepeatedDnaSequences(string s)
    {
        if (s.size() <= 10)
            return vector<string>();

        unordered_map<string, int> hash;
        vector<string> answer;
        for (int i = 0; i <= s.size() - 10; i++)
        {
            string str = s.substr(i, 10);
            if (hash[str] == 1)
                answer.push_back(str);
            hash[str]++;
        }

        return answer;
    }
};