#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cstring>
#include<string>
#include<vector>
#include<iomanip>
#include<unordered_set>
#include<unordered_map>
#include<cmath>
#include<list>
#include<bitset>
using namespace std;

#define ull unsigned long long
#define ll long long
#define lson l,mid,id<<1
#define rson mid+1,r,id<<1|1

typedef pair<int, int>pii;
typedef pair<ll, ll>pll;
typedef pair<double, double>pdd;
const double eps = 1e-6;
const int MAXN = 100005;
const int MAXM = 5005;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;
const double FINF = 1e18;
const ll MOD = 1000000007;
ll dp[50005], h[505], c[505];
int main()
{
    int t, n;
    ll sum = 0;
    scanf("%d", &t);
    while (t--)
    {
        sum = 0;
        fill(dp, dp + 50001, -LINF);
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
            scanf("%lld%lld", &h[i], &c[i]),
            sum += c[i];

        dp[0] = 0;
        for (int i = 1; i <= n; ++i)
            for (int j = sum; j >= c[i]; --j)
                if (dp[j - c[i]] != -LINF)
                    if (dp[j] == -LINF)
                        dp[j] = dp[j - c[i]] + h[i];
                    else
                    {
                        ll tmp = dp[j - c[i]] + h[i];
                        if (dp[j] * dp[j] - j*dp[j] - j*j < tmp*tmp - j*tmp - j*j)
                            dp[j] = tmp;

                    }
        ll ans = 0;
        for (int i = 0; i <= sum; ++i)
            if (dp[i] != -LINF)
                ans = max(ans, dp[i] * dp[i] - i*dp[i] - i*i);

        cout << ans << endl;
    }
}

