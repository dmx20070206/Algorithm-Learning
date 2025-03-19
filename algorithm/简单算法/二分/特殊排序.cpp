#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Forward declaration of compare API.
// bool compare(int a, int b);
// return bool means whether a is less than b.

// temp
bool compare(int a, int b)
{
    return true;
}

class Solution
{
public:
    vector<int> specialSort(int N)
    {
        if (N == 0)
            return vector<int>();

        // index, value
        vector<int> values;
        values.push_back(1);

        // sort
        for (int i = 2; i <= N; i++)
        {
            int l = 0;
            int r = values.size();
            while (l < r)
            {
                int mid = (l + r) >> 1;
                int mid_value = values[mid];
                bool big_than_mid = compare(mid_value, i);
                if (big_than_mid)
                    l = mid + 1;
                else
                    r = mid;
            }

            values.insert(values.begin() + l, i);
        }

        return values;
    }
};