#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> ALL;
// R -> [0, n)
int convert(int x)
{
    return lower_bound(ALL.begin(), ALL.end(), x) - ALL.begin();
}

int main()
{
    int n, m;

    // 科学家
    cin >> n;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    // 电影语音
    cin >> m;
    vector<int> b(m, 0);
    for (int i = 0; i < m; i++)
        cin >> b[i];
    // 电影字幕
    vector<int> c(m, 0);
    for (int i = 0; i < m; i++)
        cin >> c[i];

    vector<int> all;
    for (int i = 0; i < n; i++)
        all.push_back(a[i]);
    for (int i = 0; i < m; i++)
        all.push_back(b[i]);
    for (int i = 0; i < m; i++)
        all.push_back(c[i]);

    sort(all.begin(), all.end());

    for (int i = 0; i < all.size(); i++)
    {
        if (i == 0 || all[i] != all[i - 1])
            ALL.push_back(all[i]);
    }

    vector<int> cnts(ALL.size(), 0);

    // 统计科学家懂的语言个数
    for (int i = 0; i < n; i++)
    {
        cnts[convert(a[i])]++;
    }

    // 遍历所有电影
    int ans = 1, ans1 = 0, ans2 = 0;
    for (int i = 0; i < m; i++)
    {
        int tmp1 = cnts[convert(b[i])];
        int tmp2 = cnts[convert(c[i])];
        if (tmp1 > ans1 || (tmp1 == ans1 && tmp2 > ans2))
        {
            ans1 = tmp1;
            ans2 = tmp2;
            ans = i + 1;
        }
    }

    cout << ans << endl;
    return 0;
}