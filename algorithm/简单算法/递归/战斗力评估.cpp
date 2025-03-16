#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

bitset<32> b;

void split(int pos, vector<int> nums)
{
    if (pos < 0)
        return;

    vector<int> begin_0, begin_1;

    for (int i = 0; i < nums.size(); i++)
    {
        if ((nums[i] >> pos) & 1)
            begin_1.push_back(nums[i]);
        else
            begin_0.push_back(nums[i]);
    }

    if (!begin_1.empty() && !begin_0.empty())
        b[pos] = 1;

    if (!begin_1.empty())
        split(pos - 1, begin_1);
    if (!begin_0.empty())
        split(pos - 1, begin_0);
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    split(31, nums);

    long long ans = 1;
    for (int i = 31; i >= 0; i--)
    {
        ans <<= (b[i]);
    }
    cout << ans << endl;
    return 0;
}