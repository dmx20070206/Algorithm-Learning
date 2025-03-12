#include <iostream>
#include <vector>
#include <deque>
#include <string.h>
using namespace std;

int f[20001];
int g[20001];
class MonotonicQueue
{
public:
    deque<int> nums;
    void push(int num)
    {
        while ((int)nums.size() && nums.back() < num)
        {
            nums.pop_back();
        }
        nums.push_back(num);
    }
    void pop(int num)
    {
        if (nums.size() == 0)
            return;
        if (nums.front() == num)
            nums.pop_front();
    }
    int getMax()
    {
        if ((int)nums.size() == 0)
            return -1;
        return nums.front();
    }
};
int main()
{
    int N, V;
    cin >> N >> V;
    vector<int> weights(N + 1, 0);
    vector<int> values(N + 1, 0);
    vector<int> nums(N + 1, 0);
    for (int i = 1; i <= N; i++)
    {
        cin >> weights[i] >> values[i] >> nums[i];
    }

    // 遍历物品
    for (int i = 1; i <= 2; i++)
    {
        MonotonicQueue q;
        memcpy(g, f, sizeof(f));
        // 拆分成余数为 j 的若干同余类
        for (int j = 0; j < weights[i]; j++)
        {
            int index = 0; // k = j + index * weights[i]
            for (int k = j; k <= V; k += weights[i])
            {
                // 弹出超界元素
                q.pop(g[k - (nums[i] + 1) * weights[i]] - (index - (nums[i] + 1)) * values[i]);

                // 更新最大价值
                f[k] = max(g[k], q.getMax() + index * values[i]);

                // 加入当前元素
                q.push(g[k - weights[i]] - (index - 1) * values[i]);
                // cout << index << " " << k << " " << g[k] << " " << g[k] - index * values[i] << endl;
                // if (f[k] == 7)
                // {
                //     cout << k << " " << g[k] << " " << q.getMax() << " " << index << " " << values[i] << g[k] - index * values[i] << endl;
                // }

                index++;
            }
        }
        for (int s = 1; s <= V; s++)
        {
            cout << f[s] << " ";
        }
        cout << endl;
    }
    cout << f[V] << endl;
    return 0;
}