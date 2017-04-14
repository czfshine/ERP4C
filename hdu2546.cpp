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



int p[2017],dp[2017];
int n;
void Init(){

	memset(p,2017*sizeof(int),0);
	memset(dp,2017*sizeof(int),0);

	REP(i,1,n)
		scanf("%d",p+i);

	sort(p+1,p+1+n,greater<int>() );
	return ;
}

void Solve(){
	
	int Max=p[n];
	int m;
	scanf("%d",&m);

	if(m<5){

		print(m);
		return ;
	}
	m-=5;

	REP(i,1,n-1)
	REP(j,m,p[i])
	dp[j]=max(dp[j],dp[j-p[i]]+p[i]);

	print(m+5-dp[m]-Max);

	return ;
}

int main(){

	freopen("hdu2546.in","r",stdin);


	
	while(scanf("%d",&n)&&n)
	Init(),Solve();
	return 0;
}