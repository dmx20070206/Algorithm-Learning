#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>
using namespace std;

vector<string> split(string str)
{
    vector<string> strs;
    int left = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == ' ')
        {
            string sub = str.substr(left, i - left);
            // number
            if (isdigit(str[left]))
            {
                strs.push_back(sub);
            }
            // ops
            else
            {
                for (int j = 0; j < sub.size(); j++)
                    strs.push_back(string(1, sub[j]));
            }
            left = i + 1;
        }
    }
    return strs;
}

int main()
{
    // split str
    string str;
    getline(cin, str);
    vector<string> strs = split(str + " ");
    strs.pop_back();

    // calculate
    stack<long long> s;
    for (int i = 0; i < strs.size(); i++)
    {
        // number
        if (isdigit(strs[i][0]))
        {
            s.push(stoll(strs[i]));
        }
        // ops
        else
        {
            long long num1 = s.top();
            s.pop();
            long long num2 = s.top();
            s.pop();
            switch (strs[i][0])
            {
            case '+':
                s.push(num1 + num2);
                break;
            case '-':
                s.push(num2 - num1);
                break;
            case '*':
                s.push(num1 * num2);
                break;
            case '/':
                s.push(num2 / num1);
                break;
            default:
                break;
            }
        }
    }
    cout << s.top() << endl;
    return 0;
}