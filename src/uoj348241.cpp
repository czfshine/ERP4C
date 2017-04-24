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

int cou=0;

void dfs(int n,int p[],int a[],int cur){


	if(cur==n){
		REP(i,0,n-1){

			cout<<a[i];

		}
		cout<<endl;
		cou++;
	}else{

		REP(i,0,n-1){
			a[cur]=p[i];
			dfs(n,p,a,cur+1);
		}

	}
}

void Init(){


	return ;
}

void Solve(){
	int p[]={1,2,3,4};
	int a[800];
	dfs(4,p,a,0);

	return ;
}

int main(){

	freopen("uoj348241.in","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--)
	Init(),Solve();
	return 0;
}