#include <iostream>
using namespace std;

int main()
{
    long long a, b, p;
    cin >> a >> b >> p;

    long long ans = 0;
    for (; b; b >>= 1)
    {
        if (b & 1)
            ans = (ans + a) % p;
        a = a * 2 % p;
    }

    cout << ans << endl;

    return 0;
}