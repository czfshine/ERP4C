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

#define SIZE 1001
int i, j, n, ans;
int a[SIZE];
int d[SIZE];
 

void Init(){

	REP(i,1,n)
   		cin >> a[i];

   	
   	ans=0;
	return ;
}

void Solve(){
	REP(i,1,n)
	{
		d[i] = 1;
		REP(j,1,i-1)
			if (a[j] < a[i] && d[i] < d[j] + 1) 
				d[i] = d[j] + 1;
   		if (d[i] > ans) ans = d[i];
	}

	print(ans);

	return ;
}

int main(){

	freopen("uoj8596.in","r",stdin);

	while(cin >> n && n)
	Init(),Solve();
	return 0;
}