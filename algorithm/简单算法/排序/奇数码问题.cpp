#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

ll merge_sort(int l, vector<int> &v, int r)
{
    if (l >= r)
        return 0;

    int mid = (l + r) >> 1;
    ll cntl = merge_sort(l, v, mid);
    ll cntr = merge_sort(mid + 1, v, r);

    int i = l;
    int j = mid + 1;
    ll cnt = 0;
    vector<int> temp;
    for (int k = l; k <= r; k++)
    {
        if (j > r || i <= mid && v[i] <= v[j])
        {
            temp.push_back(v[i++]);
        }
        else
        {
            temp.push_back(v[j++]);
            cnt += mid - i + 1;
        }
    }

    for (int i = l; i <= r; i++)
    {
        v[i] = temp[i - l];
    }

    return cntl + cntr + cnt;
}

int main()
{
    int n;
    while (cin >> n)
    {
        vector<int> first;
        vector<int> second;

        for (int i = 0; i < n * n; i++)
        {
            int num;
            cin >> num;
            if (num != 0)
                first.push_back(num);
        }
        for (int i = 0; i < n * n; i++)
        {
            int num;
            cin >> num;
            if (num != 0)
                second.push_back(num);
        }

        ll cnt1 = merge_sort(0, first, (int)first.size() - 1);
        ll cnt2 = merge_sort(0, second, (int)second.size() - 1);
        if (cnt1 % 2 == cnt2 % 2)
            cout << "TAK" << endl;
        else
            cout << "NIE" << endl;
    }
    return 0;
}