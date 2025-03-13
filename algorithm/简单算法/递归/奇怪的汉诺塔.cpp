#include <iostream>
#include <string.h>
using namespace std;
long long three[13];
long long four[13];

int main()
{
    memset(three, 0, sizeof three);
    memset(four, 0, sizeof four);

    // three
    three[1] = 1;
    for (int i = 1; i <= 12; i++)
        three[i] = three[i - 1] * 2 + 1;

    // four
    four[1] = 1;
    for (int i = 1; i <= 12; i++)
    {
        for (int k = 1; k < i; k++)
        {
            if (four[i] == 0)
                four[i] = 2 * four[k] + three[i - k];
            else
                four[i] = min(four[i], 2 * four[k] + three[i - k]);
        }
    }

    for (int i = 1; i <= 12; i++)
    {
        cout << four[i] << endl;
    }
    return 0;
}