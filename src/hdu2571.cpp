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

int a[20][1005];
int dp[25][1005];
int n,m;
void Init(){

	
	scanf("%d%d",&n,&m);

	REP(i,1,n){
		REP(j,1,m){

			scanf("%d",&a[i][j]);
		}
	}


	return ;
}

void Solve(){
	REP(i,0,m-1)
		dp[0][i]=-105;
	REP(i,0,n-1)
		dp[i][0]=-105;
	dp[0][1]=dp[1][0]=0;
	REP(i,1,n)
	REP(j,1,m)
	{

		dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		REP(k,2,m)
			if(j%k==0)
				dp[i][j]=max(dp[i][j],dp[i][j/k]);
		dp[i][j]+=a[i][j];
	}
	print(dp[n][m]);

	REP(i,1,n)
	{

		REP(j,1,m){

			cout<<dp[i][j]<<"\t";
		}
		cout<<"\n"；
	}
	return ;
}

int main(){

	freopen("data.in","r",stdin);
	int T ;
	scanf("%d",&T);
	while(T--)
	Init(),Solve();
	return 0;
}