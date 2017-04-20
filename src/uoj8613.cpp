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



int dp[200005];
int q[200005];
int a[200005];
int g[200005];
int n;


void Init(){

    REP(i,1,n+1){scanf("%d",&(a[i]));g[i]=a[i]+i;}
    REP(i,n+1,n+n/2+1){a[i]=a[i-n];g[i]=a[i]+i;}
	return ;
}

void Solve(){
	
	q[1]=1;
    int head=1,tail=1;
    for(int i=2;i<=n+n/2;i++)
    {
        while(i-q[head]>n/2)head++;
        dp[i]=g[i]+a[q[head]]-q[head];
        while(a[i]-i>=a[q[tail]]-q[tail]&&tail>=head)tail--;
        q[++tail]=i;
    }
    int ans=0;
    for(int i=2;i<=n+n/2;i++)
        ans=max(ans,dp[i]);
    printf("%d",(ans));
	return ;
}
int main(){

	freopen("uoj8613.in","r",stdin);


	while((scanf("%d",&(n)))&&n)
	Init(),Solve();
	return 0;
}