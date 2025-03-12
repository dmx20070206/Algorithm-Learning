#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Element
{
public:
    int num;
    int index;
    Element(int num, int index)
    {
        this->num = num;
        this->index = index;
    }
};

int dp[32][5005];
int main()
{
    int cookies, children;
    cin >> children >> cookies;
    vector<Element> nums;
    nums.push_back(Element(0, -1));
    for (int i = 1; i <= children; i++)
    {
        int num;
        cin >> num;
        nums.push_back(Element(num, i));
    }

    sort(nums.begin() + 1, nums.end(), [](Element a, Element b)
         { return a.num > b.num; });

    for (int i = 2; i <= children; i++)
    {
        for (int j = i; j <= cookies; j++)
        {
            int case1 = INT16_MAX, case2 = INT16_MAX;

            // i <- >1
            if (j - i >= i)
                case1 = dp[i][j - i];

            // i <- 1
            for (int k = 0; k <= i - 1; k++)
            {
                if (k == 0 && j != i)
                    continue;

                if (j >= k + i)
                {
                    int sum = 0;
                    for (int t = k + 1; t <= i; t++)
                        sum += nums[t].num;
                    sum *= k;
                    case2 = min(case2, sum + dp[k][j - i + k]);
                }
            }

            dp[i][j] = min(case1, case2);
        }
    }

    cout << dp[children][cookies] << endl;
    return 0;
}