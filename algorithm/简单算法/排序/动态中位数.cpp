#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int P;
    cin >> P;
    while (P--)
    {
        // 大根堆
        priority_queue<int, vector<int>, less<int>> q_big;
        // 小根堆
        priority_queue<int, vector<int>, greater<int>> q_small;

        int num, M;
        cin >> num >> M;

        vector<int> nums(M, 0);
        for (int i = 0; i < M; i++)
            cin >> nums[i];

        int cnt = 0;

        cout << num << " " << M / 2 + 1 << endl;
        for (int i = 0; i < M; i++)
        {
            if (!q_big.empty() && nums[i] < q_big.top())
                q_big.push(nums[i]);
            else
                q_small.push(nums[i]);
            if (q_small.size() >= q_big.size() + 2)
            {
                q_big.push(q_small.top());
                q_small.pop();
            }
            if (q_big.size() >= q_small.size() + 1)
            {
                q_small.push(q_big.top());
                q_big.pop();
            }

            if (i % 2 == 0)
            {
                cnt++;
                if (cnt > 10)
                {
                    cnt = 1;
                    cout << endl;
                }
                cout << q_small.top() << " ";
            }
        }
        cout << endl;
    }
    return 0;
}