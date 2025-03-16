#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        long long ans = 1;
        for (int i = 0; i < m; i++)
        {
            ans *= n - i;
            ans /= i + 1;
        }
        cout << ans << endl;
    }
    return 0;
}