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


#define MAX 1999 

int h[55];  
int l[55];  
int dp[55][MAX];  
int n;  

void Init(){
	scanf("%d",&n);
	REP(i,0,n-1) scanf("%d",h+i);  
    REP(i,0,n-1) scanf("%d",l+i);  
    REP(j,0,MAX-1) dp[0][j] = l[0] <= j ? h[0] : 0;
	return ;
}

void Solve(){

    REP(i,1,n-1) 
        REP(j,0,MAX-1)  
            if(l[i]>j) dp[i][j] = dp[i-1][j];  
            else dp[i][j] = max(dp[i-1][j],dp[i-1][j-l[i]]+h[i]);   
    print(dp[n-1][MAX-1]+1); 
	return ;
}

int main(){

	freopen("uoj8615.in","r",stdin);



	Init(),Solve();
	return 0;
}