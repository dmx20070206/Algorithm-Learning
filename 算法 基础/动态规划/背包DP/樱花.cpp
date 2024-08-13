#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
int dp[1500];

int marginTime(string beginStr, string endStr)
{
    int beginH, beginM, endH, endM;
    if (beginStr[1] == ':')
    {
        beginH = stoi(beginStr.substr(0, 1));
        beginM = stoi(beginStr.substr(2, 2));
    }
    else
    {
        beginH = stoi(beginStr.substr(0, 2));
        beginM = stoi(beginStr.substr(3, 2));
    }
    if (endStr[1] == ':')
    {
        endH = stoi(endStr.substr(0, 1));
        endM = stoi(endStr.substr(2, 2));
    }
    else
    {
        endH = stoi(endStr.substr(0, 2));
        endM = stoi(endStr.substr(3, 2));
    }
    return 60 * (endH - beginH) + (endM - beginM);
}

int main()
{
    string beginTime, endTime;
    int num;
    cin >> beginTime >> endTime >> num;
    int time = marginTime(beginTime, endTime);

    vector<int> weights;
    vector<int> values;
    vector<int> nums;
    for (int i = 0; i < num; i++)
    {
        int weight, value, num;
        cin >> weight >> value >> num;
        if (num == 0)
        {
            weights.push_back(weight);
            values.push_back(value);
            nums.push_back(num);
        }
        else
        {
            int k = 1;
            while (k < num)
            {
                weights.push_back(k * weight);
                values.push_back(k * value);
                num -= k;
                k *= 2;
                nums.push_back(1);
            }
            if (num > 0)
            {
                weights.push_back(num * weight);
                values.push_back(num * value);
                nums.push_back(1);
            }
        }
    }

    for (int i = 0; i < weights.size(); i++)
    {
        if (nums[i] == 0)
        {
            for (int j = weights[i]; j <= time; j++)
                dp[j] = max(dp[j], dp[j - weights[i]] + values[i]);
        }
        else
        {
            for (int j = time; j >= weights[i]; j--)
                dp[j] = max(dp[j], dp[j - weights[i]] + values[i]);
        }
    }

    cout << dp[time] << endl;
    return 0;
}