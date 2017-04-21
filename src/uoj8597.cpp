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


int n,m;

int a[1005];
int dp[1005][1005];
void Init(){

	cin>>n>>m;

	REP(i,1,n)
		cin>>a[i];
	sort ( a,a+n);
	return ;
}

void Solve(){
	
	REP(i,1,n)       //处理边界  
    	dp[1][i]=(a[i]-a[1])*(a[i]-a[1]);  
    REP(i,2,m)
    {  
        REP(j,i+1,n)
        {  
            int min=INF;  
            REP(k,1,j-i+1) 
            {  
                if(min>dp[i-1][j-k]+(a[j]-a[j-k+1])*(a[j]-a[j-k+1]))  
                   min=dp[i-1][j-k]+(a[j]-a[j-k+1])*(a[j]-a[j-k+1]);  
            }  
            dp[i][j]=min;  
        }  
    }
    
    cout<<dp[m][n]<<endl;  
	return ;
}

int main(){

	freopen("uoj8597.in","r",stdin);



	Init(),Solve();
	return 0;
}