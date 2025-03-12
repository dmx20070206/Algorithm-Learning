// https://www.luogu.com.cn/problem/P1080
// 需要高精度处理大数乘法？后续补充

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
typedef long long ll;

class People
{
public:
    ll leftNum;
    ll rightNum;
    People(ll left, ll right)
    {
        this->leftNum = left;
        this->rightNum = right;
    }
};

class Compare
{
public:
    bool operator()(People &p1, People &p2)
    {
        return max(p2.rightNum, p1.leftNum * p1.rightNum) < max(p1.rightNum, p2.leftNum * p2.rightNum);
    }
};

ll DownDiv(ll one, ll two)
{
    int i = one / two;
    if (two * i > one)
        i--;
    return i;
}

int main()
{
    ll n;
    cin >> n;
    ll kingLeft, kingRight;
    cin >> kingLeft >> kingRight;
    vector<People> peoples;
    for (ll i = 0; i < n; i++)
    {
        ll num1, num2;
        cin >> num1 >> num2;
        peoples.push_back(People(num1, num2));
    }
    sort(peoples.begin(), peoples.end(), Compare());
    ll curMulNum = kingLeft;
    ll maxNum = 0;
    for (ll i = 0; i < (int)peoples.size(); i++)
    {
        maxNum = max(maxNum, DownDiv(curMulNum, peoples[i].rightNum));
        curMulNum *= peoples[i].leftNum;
    }
    cout << maxNum << endl;
    return 0;
}