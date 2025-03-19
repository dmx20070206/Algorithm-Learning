#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N, F;
    cin >> N >> F;

    vector<int> nums(N + 1, 0);
    for (int i = 1; i <= N; i++)
        cin >> nums[i];

    vector<int> sum(N + 1, 0);
    for (int i = 1; i <= N; i++)
        sum[i] = sum[i - 1] + nums[i];

    double l = 0;
    double r = 2000;

    while (r - l > 1e-6)
    {
        double mid = (r + l) / 2;

        // valid
        bool valid = false;
        double min_before = 1e10;
        for (int i = F; i <= N; i++)
        {
            min_before = min(min_before, sum[i - F] - mid * (i - F));
            if (sum[i] - mid * i - min_before >= 0)
            {
                valid = true;
                break;
            }
        }

        if (valid)
            l = mid;
        else
            r = mid;
    }

    cout << (int)(r * 1000) << endl;
    return 0;
}