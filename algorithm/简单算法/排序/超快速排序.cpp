#include <iostream>
#include <vector>
using namespace std;

long long cnt = 0;
void merge_sort(int l, vector<int> &nums, int r)
{
    if (l == r)
        return;

    int mid = (l + r) >> 1;
    merge_sort(l, nums, mid);
    merge_sort(mid + 1, nums, r);

    vector<int> temp(r - l + 1, 0);
    int i = l;
    int j = mid + 1;
    for (int k = 0; k <= r - l; k++)
    {
        if (j > r || i <= mid && nums[i] <= nums[j])
        {
            temp[k] = nums[i];
            i++;
        }
        else
        {
            temp[k] = nums[j];
            cnt += mid - i + 1;
            j++;
        }
    }
    for (int i = l; i <= r; i++)
    {
        nums[i] = temp[i - l];
    }
}

int main()
{
    int n;
    while (cin >> n && n)
    {
        vector<int> nums(n, 0);
        for (int i = 0; i < n; i++)
            cin >> nums[i];

        merge_sort(0, nums, nums.size() - 1);
        cout << cnt << endl;
        cnt = 0;
    }
    return 0;
}