#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    vector<int> minus{nums[0]};
    long long up = 0, down = 0;
    for (int i = 1; i < n; i++)
        minus.push_back(nums[i] - nums[i - 1]);
    for (int i = 1; i < n; i++)
    {
        up += minus[i] > 0 ? minus[i] : 0;
        down += minus[i] < 0 ? -minus[i] : 0;
    }

    cout << max(up, down) << endl;
    cout << max(up, down) - min(up, down) + 1 << endl;

    return 0;
}