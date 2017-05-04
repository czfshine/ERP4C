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



char a[300005],b[100005];

void Init(){
	cin>>b;

	return ;
}

void Solve(){
	int lena;
	lena =strlen(a);

	REP(i,0,lena-1){
		a[lena+i]=a[i];
	}
	a[lena*2]=0;

	cout<<(((search(a,a+2*lena,b,b+strlen(b))-a)<2*lena)?"yes":"no")<<endl;

	return ;
}

int main(){
#ifdef LOCAL
	freopen("hdu2203.in","r",stdin);
#endif

	while(cin>>a)
	Init(),Solve();
	return 0;
}