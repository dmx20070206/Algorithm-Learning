#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

typedef long long ll;
ll dp[31][31][31][31][31];
int main()
{
    while (true)
    {
        ll rowNum;
        cin >> rowNum;

        if (rowNum == 0)
            break;

        vector<ll> rowPerNum(5, 0);
        for (ll i = 0; i < rowNum; i++)
            cin >> rowPerNum[i];

        memset(dp, 0, sizeof dp);
        dp[0][0][0][0][0] = 1;
        for (ll a1 = 0; a1 <= rowPerNum[0]; a1++)
            for (ll a2 = 0; a2 <= min(a1, rowPerNum[1]); a2++)
                for (ll a3 = 0; a3 <= min(a2, rowPerNum[2]); a3++)
                    for (ll a4 = 0; a4 <= min(a3, rowPerNum[3]); a4++)
                        for (ll a5 = 0; a5 <= min(a4, rowPerNum[4]); a5++)
                        {
                            ll &num = dp[a1][a2][a3][a4][a5];

                            if (a1 - 1 >= a2 && a1)
                                num += dp[a1 - 1][a2][a3][a4][a5];
                            if (a2 - 1 >= a3 && a2)
                                num += dp[a1][a2 - 1][a3][a4][a5];
                            if (a3 - 1 >= a4 && a3)
                                num += dp[a1][a2][a3 - 1][a4][a5];
                            if (a4 - 1 >= a5 && a4)
                                num += dp[a1][a2][a3][a4 - 1][a5];
                            if (a5)
                                num += dp[a1][a2][a3][a4][a5 - 1];
                        }
        cout << dp[rowPerNum[0]][rowPerNum[1]][rowPerNum[2]][rowPerNum[3]][rowPerNum[4]] << endl;
    }
    return 0;
}