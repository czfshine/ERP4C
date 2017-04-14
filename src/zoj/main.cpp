/* ZOJ 3956
There are n courses in the course selection system of Marjar University.
 The i-th course is described by two values:
 happiness Hi and credit Ci.

 If a student selects m courses x1, x2, ..., xm,
 then his comfort level of the semester can be defined as follows:

$$(\sum_{i=1}^{m} H_{x_i})^2-(\sum_{i=1}^{m} H_{x_i})\times(\sum_{i=1}^{m} C_{x_i})-(\sum_{i=1}^{m} C_{x_i})^2$$

Edward, a student in Marjar University, wants to select some courses
(also he can select no courses, then his comfort level is 0)
to maximize his comfort level.

Can you help him?

There are multiple test cases. The first line of input contains an integer T,
 indicating the number of test cases. For each test case:

The first line contains a integer n (1 ≤ n ≤ 500) -- the number of cources.

Each of the next n lines contains two integers Hi and Ci (1 ≤ Hi ≤ 10000, 1 ≤ Ci ≤ 100).

It is guaranteed that the sum of all n does not exceed 5000.

We kindly remind you that this problem contains large I/O file,
so it's recommended to use a faster I/O method. For example,
you can use scanf/printf instead of cin/cout in C++.




题意:给了n个物品，每个物品有两个值，H和C 问你怎么取， 使最后
(∑i=1mHxi)2−(∑i=1mHxi)×(∑i=1mCxi)−(∑i=1mCxi)2

这个东西最大。

分析：dp[i] 表示 取到C的总和为i的时候 使答案最大的 H的和为多少，
剩下就和背包差不多了，需要注意的是dp值的初始化，需要取成-inf；
*/

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


typedef   long long ll;
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
		for (int i = 1; i <= n; ++i)scanf("%lld%lld", &h[i], &c[i]), sum += c[i];
		dp[0] = 0;
		for (int i = 1; i <= n; ++i)
		{
			for (int j = sum; j >= c[i]; --j)
			{
				if (dp[j - c[i]] != -LINF)
				{
					if (dp[j] == -LINF)dp[j] = dp[j - c[i]] + h[i];
					else
					{
						ll tmp = dp[j - c[i]] + h[i];
						if (dp[j] * dp[j] - j*dp[j] - j*j < tmp*tmp - j*tmp - j*j)
						{
							dp[j] = tmp;
						}
					}
				}
			}
		}
		ll ans = 0;
		for (int i = 0; i <= sum; ++i)
		{
			if (dp[i] != -LINF)
			{
				ans = max(ans, dp[i] * dp[i] - i*dp[i] - i*i);
			}
		}
		cout << ans << endl;
	}
}
