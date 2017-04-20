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


int G,L,i,j,T=1,dp[31][31];

void Init(){

	memset(dp,0,sizeof dp);
	return ;
}

void Solve(){
	
	dp[0][0]=1;
	REP(i,1,G)
	{
		dp[i][0]=i;
		REP(j,1,L)
			if(j>=i)
				dp[i][j]=pow(2.0,i)-1;
			else
				dp[i][j]=dp[i-1][j]+1+dp[i-1][j-1];
	}

	printf("Case %d: %d\n",T++,dp[G][L]);
	
	return ;
}

int main(){

	freopen("pku1243.in","r",stdin);


	while(scanf("%d %d",&G,&L) && G)
	Init(),Solve();
	return 0;
}