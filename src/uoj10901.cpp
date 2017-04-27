#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <cstring>
#include <string>
#include <vector>
#include <iomanip>
#include <cmath>
#include <list>
#include <bitset>

using namespace std;

#define ll long long 
#define lson l,mid,id<<1
#define rson mid+1,r,id<<1|1

typedef pair<int, int>pii;
typedef pair<ll, ll>pll;
typedef pair<double, double>pdd;

const double eps = 1e-6;
const ll  LINF = 0x3f3f3f3f3f3f3f3fLL;
const int INF = 0x3f3f3f3f;
const double FINF = 1e18;

#define x first
#define y second

#define REP(i,j,k) for(int i =(j);i<=(k);i++)
#define REPD(i,j,k) for(int i =(j);i>=(k);i--)
#define print(x) cout<<(x)<<endl;
#define IOS ios::sync_with_stdio(0);cin.tie(0);


int n;

int a[1005],dp[1005];
void Init(){
	REP(i,0,n-1){
		scanf("%d",a+i);
		dp[i]=1;
	}

	return ;
}

void Solve(){
	int t=1;
	REP(i,0,n-1){
		REP(j,0,i-1){
			if(((dp[j]%2)&& a[i]<a[j])|| ((dp[j]%2 == 0) && a[i]>a[j])){
				dp[i]=max(dp[i],dp[j]+1);
			}
		}

		t=max(t,dp[i]);
	}

	printf("%d\n",t);

	return ;
}

int main(){
#ifdef LOCAL
	freopen("uoj10901.in","r",stdin);
#endif

	while(scanf("%d",&n) && n)
	Init(),Solve();
	return 0;
}