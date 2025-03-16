#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
    int N, P, H, M;
    cin >> N >> P >> H >> M;

    vector<int> nums(N, 0);
    map<pair<int, int>, bool> maps;

    int A, B;
    for (int i = 0; i < M; i++)
    {
        cin >> A >> B;
        A--;
        B--;

        int left = min(A, B);
        int right = max(A, B);

        if (right <= left + 1)
            continue;

        if (maps[make_pair(left, right)])
            continue;
        else
            maps[make_pair(left, right)] = true;

        nums[left + 1]--;
        nums[right]++;
    }

    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        ans += nums[i];
        cout << ans + H << endl;
    }
    return 0;
}