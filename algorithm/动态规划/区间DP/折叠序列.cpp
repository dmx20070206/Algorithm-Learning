#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
#define maxn 1061109567

string str;
int dp[100][100];
int print[100][100];

void printAnswer(int left, int right)
{
    if (left > right)
        return;

    // 只有一个字符，直接输出
    if (left == right)
    {
        cout << str[left];
        return;
    }

    int p = print[left][right];
    if (p == maxn)
    {
        for (int i = left; i <= right; i++)
        {
            cout << str[i];
        }
        return;
    }

    // 如果是子串重复的形式
    if (p < 0)
    {
        int time = (right - left + 1) / (-p);
        cout << time << '(';
        printAnswer(left, left - p - 1);
        cout << ')';
    }
    // 如果是区间拼接的形式
    else
    {
        printAnswer(left, p);
        printAnswer(p + 1, right);
    }
}

int main()
{
    cin >> str;
    int size = str.size();
    memset(dp, 0x3f, sizeof(dp));
    memset(print, 0x3f, sizeof print);

    for (int len = 1; len <= size; len++)
    {
        for (int left = 0; left < size - len + 1; left++)
        {
            int right = left + len - 1;
            if (len == 1)
                dp[left][right] = 1;
            else
                // 状态转移1：当前区间由更小的两个区间拼接而成
                for (int mid = left; mid < right; mid++)
                {
                    if (dp[left][mid] + dp[mid + 1][right] < dp[left][right])
                    {
                        print[left][right] = mid;
                        dp[left][right] = dp[left][mid] + dp[mid + 1][right];
                    }
                }

            // 状态转移2：当前区间作为子串重复拼成下个区间
            int num = (size - right - 1) / len;
            for (int time = 1; time <= num; time++)
            {
                for (int i = 1; i <= len; i++)
                {
                    if (str[right + (time - 1) * len + i] != str[left + i - 1])
                    {
                        time = num + 1;
                        break;
                    }
                }
                int numlen = to_string(time + 1).size();
                if (time <= num && dp[left][right] + (2 + numlen) < dp[left][right + time * len])
                {
                    print[left][right + time * len] = -len;
                    dp[left][right + time * len] = dp[left][right] + (2 + numlen);
                };
            }
        }
    }
    printAnswer(0, size - 1);
    return 0;
}