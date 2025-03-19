#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> A(N, 0);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    sort(A.begin(), A.end());

    int ans = 0;
    int pos = A[A.size() / 2];
    for (int i = 0; i < A.size(); i++)
        ans += abs(A[i] - pos);

    cout << ans << endl;

    return 0;
}