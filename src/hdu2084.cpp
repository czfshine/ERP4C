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



int a[105][105];
int n;

int dp[105][105]={0};

void Init(){
	scanf("%d",&n);


	REP(i,1,n)
	REP(j,1,i){

		scanf("%d",&a[i][j]);
	}

	return ;
}

void Solve(){
	
	dp[0][0]=0;

	REPD(i,n,1)
	REP(j,1,i){
		dp[i][j]=a[i][j]+max(dp[i+1][j],dp[i+1][j-1]);
	}

	REP(i,1,n){
	REP(j,1,n){
	cout<<dp[i][j]<<"\t";}
	cout<<endl;}
	return ;
}

int main(){

	freopen("hdu2084.in","r",stdin);

	int T;
	scanf("%d",&T);


	while(T--)
	Init(),Solve();
	return 0;
}