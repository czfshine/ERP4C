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

int dp[100005];
void Init(){

	scanf("%d",&n);

	REP(i,1,n){
		scanf("%d",dp+i);
	}
	return ;
}

void Solve(){
	dp[1]=1;
	dp[n]=1;
	int m;
	REP(i,2,n-1){
		m=min(dp[i-1],dp[i+1]);
		if(dp[i]-m>1){
			dp[i]=m+1;
		}
	}
	REPD(i,n-1,2){
		m=min(dp[i-1],dp[i+1]);
		if(dp[i]-m>1){
			dp[i]=m+1;
		}
	}
	int ma=0;
	REP(i,1,n){
		ma=max(ma,dp[i]);
	}
	printf("%d\n",ma);
	return ;
}

int main(){
#ifdef LOCAL
	freopen("uoj18092.in","r",stdin);
#endif


	Init(),Solve();
	return 0;
}