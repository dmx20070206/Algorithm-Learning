#include <iostream>
using namespace std;

int main()
{
    unsigned long long a, b, p;
    cin >> a >> b >> p;

    unsigned long long ans = 1;

    for (; b; b = b >> 1)
    {
        if (b & 1)
            ans = ans * a % p;
        a = a * a % p;
    }

    cout << ans % p << endl;

    return 0;
}