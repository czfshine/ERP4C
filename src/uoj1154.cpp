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


const int maxn=1000+10;  
char a[maxn];  
int dp[maxn];  

int k,k,n;  

void Init(){
	scanf("%s",a+1);
	return ;
}

void Solve(){
	
	n=strlen(a+1);  
    dp[0]=0;  
    REP(i,1,n) dp[i]=INF;  
      REP(i,1,n) {  
        for(j=i,k=i;j<=n&&k>0;j++,k--) {  
            if(a[j]==a[k]) dp[j]=min(dp[j],dp[k-1]+1);  
            else break;  
        }  
        for(j=i+1,k=i;j<=n&&k>0;j++,k--) {  
            if(a[j]==a[k]) dp[j]=min(dp[j],dp[k-1]+1);  
            else break;  
        }  
    }  

    printf("%d\n",dp[n]);  
	return ;
}

int main(){

	freopen("uoj1154.in","r",stdin);


	int T;
	scanf("%d",&T);

	while(T--)
	Init(),Solve();
	return 0;
}