


/*
题意：

一条直线有N个村庄，要建p个邮局，使距离和最小。

思路：
明显dp：先处理各个区间的最短的距离（打表）。
dis[i][j]=dis[i][j-1]+x[j]-x[(i+j)/2]; （村庄位置为x[i]）
dp[i][j]为i个村庄j个邮局的最短距离。
dp[i][j]=min(dp[i][j],dp[k][j-1]+dis[k+1][i]) 

*/
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

int dp[500][35]={0}; 
int dis[500][500]={0}; 
int x[500]; 

int v,p,i,j,k;  

void printarray2(int* a,int len1,int len2){

	REP(i,0,len1-1){
		REP(j,0,len2-1){
			cout<<*(a+i*len2+j);
		}
		cout<<endl;
	}
}
void Init(){

	scanf("%d%d",&v,&p);
	REP(i,1,v) 
		scanf("%d",&x[i]);

	return ;
}

void Solve(){
	REP(i,1,v)
        REP(j,i+1,v) 
            dis[i][j]=dis[i][j-1]+x[j]-x[(i+j)/2];  
 	printarray2((int *) dis,v+1,v+1);
 	cout<<dis[2][2];
    REP(i,1,v) 
    {  
        dp[i][i]=0;  
        dp[i][1]=dis[1][i]; //只有一个邮局  
    }  

    REP(j,2,p)  
        REP(i,j+1,v) 
        {  
        	dp[i][j]=INF;  
            REP(k,j-1,i-1) 
            {  
                dp[i][j]=min(dp[i][j],dp[k][j-1]+dis[k+1][i]);  
            }  
        }   

    print(dp[v][p]);

	return ;
}

int main(){
#ifdef LOCAL
	freopen("poj1160.in","r",stdin);
#endif


	Init(),Solve();
	return 0;
}