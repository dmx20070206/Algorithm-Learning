#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Compare
{
public:
    bool operator()(string str1, string str2)
    {
        return str1 + str2 > str2 + str1;
    }
};

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        priority_queue<string, vector<string>, Compare> q;
        for (int i = 0; i < N; i++)
        {
            string str;
            cin >> str;
            q.push(str);
        }

        while (!q.empty())
        {
            cout << q.top();
            q.pop();
        }
        cout << endl;
    }
    return 0;
}