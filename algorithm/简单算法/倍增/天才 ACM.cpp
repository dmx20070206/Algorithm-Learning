#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

const int N = 500005;

int n, m;
int ans;
ll T;
ll w[N], t[N];
ll tmp[N];

ll sq(ll x)
{
    return x * x;
}

bool check(int l, int mid, int r) // 判断区间 [l, r) 是否合法，并将 t 中的 [l, mid) 区间和 [mid, r) 区间合并到 tmp 中
{
    for (int i = mid; i < r; i++) // 将 w 数组的 [l, r) 区间复制到 t 的 [l, r) 区间中
        t[i] = w[i];
    sort(t + mid, t + r);      // 将 t 的 [mid, r) 排序
    int i = l, j = mid, k = 0; // 双指针进行区间合并
    while (i != mid && j != r) // 当 i 不到 mid 且 j 不到 r 时，执行循环
        if (t[i] < t[j])       // 如果 t[i] 比 t[j] 小，那么将 t[i] 放入 tmp 中
            tmp[k++] = t[i++];
        else // 否则将 t[j] 放入 tmp 中
            tmp[k++] = t[j++];
    while (i != mid)
        tmp[k++] = t[i++]; // 处理剩下的元素
    while (j != r)
        tmp[k++] = t[j++];
    ll sum = 0; // 计算校验值
    for (i = 0; i < m && i < k; i++, k--)
        sum += sq(tmp[i] - tmp[k - 1]);
    return sum <= T; // 返回当前区间 [l, r) 是否合法
}

int main()
{
    int K;
    scanf("%d", &K);
    while (K--)
    {
        scanf("%d %d %lld\n", &n, &m, &T);
        for (int i = 0; i < n; i++)
            scanf("%lld", &w[i]);
        ans = 0;
        int len;
        int start = 0, end = 0;
        while (end < n)
        {
            len = 1;
            while (len)
            {
                if (end + len <= n && check(start, end, end + len)) // 如果 w 的 [start, end + len) 区间合法
                {
                    end += len, len <<= 1;
                    if (end >= n)
                        break;                        // 一个小剪枝，如果 end >= n，那么直接跳出
                    for (int i = start; i < end; i++) // 在 check 时，已经将 t 数组的 [start, end + len) 这段区间归并在 tmp 中了。现在只需要将 tmp 中的有序数组复制到 t 中即可
                        t[i] = tmp[i - start];        // 复制的时候注意下标变换，tmp 是从 0 开始存的，t 是从 start 开始存的
                }
                else
                    len >>= 1;
            }
            start = end;
            ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}
