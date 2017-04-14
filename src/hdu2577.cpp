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

char c[1000];
int dp[105][2];

void Init(){
	cin>>c+1;

	return ;
}

void Solve(){

	int len=strlen(c+1);

	dp[0][0]=0;
	dp[0][1]=2;

	REP(i,1,len){

		if(c[i]>='A'&&c[i]<='Z'){

			dp[i][1]=min(dp[i-1][1]+1,dp[i-1][0]+2);
			dp[i][0]=min(dp[i-1][1]+2,dp[i-1][0]+2);

		}else{
			dp[i][0]=min(dp[i-1][0]+1,dp[i-1][1]+2);
			dp[i][1]=min(dp[i-1][0]+2,dp[i-1][1]+2);

		}

	}
	print(min(dp[len][0],dp[len][1]+1));
	return ;
}

int main(){

	freopen("data.in","r",stdin);

	int T;
	scanf("%d",&T);

	while(T--)
	Init(),Solve();
	return 0;
}