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


char a[3000],b[3000];

int dp[3000][3000];



void Init(){


	return ;
}

void Solve(){
	int la,lb;
	la=strlen(a);
	lb=strlen(b);

	REP(i,0,la-1)
		REP(j,0,lb-1)
			if(a[i]==b[j])
				if(i==0|| j==0 )
					dp[i][j]=1;
				else
					dp[i][j]=dp[i-1][j-1]+1;
				
			
			else
				dp[i][j]=0;
			
		

	int end=0;
	int ans=dp[1][1];
	REPD(i,la-1,0)    
        REP(j,0,lb-1) {
		if(dp[i][j]>ans){
			ans=dp[i][j];
			end=i;
		}
	}

	REP(i,end-ans+1,end){
		cout<<a[i];
	}
	cout<<endl;

	return ;
}

int main(){

	freopen("uoj11077_t.in","r",stdin);


	while(cin>>a>>b)
	Init(),Solve();
	return 0;
}