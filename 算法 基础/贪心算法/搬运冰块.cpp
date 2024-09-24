#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
class Compare
{
public:
    bool operator()(pair<ll, ll> &p1, pair<ll, ll> &p2)
    {
        ll time1 = (p1.first) * p2.second;
        ll time2 = (p2.first) * p1.second;
        return time1 >= time2;
    }
};

int main()
{
    ll N;
    cin >> N;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, Compare> q;
    for (ll i = 0; i < N; i++)
    {
        ll num1, num2;
        cin >> num1 >> num2;
        q.push(make_pair(num1, num2));
    }
    ll time = 0;
    ll minCost = 0;
    while (!q.empty())
    {
        pair<ll, ll> p = q.top();
        q.pop();
        minCost += time * p.second;
        time += p.first;
    }
    cout << minCost << endl;
    return 0;
}