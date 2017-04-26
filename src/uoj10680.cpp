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

int dpa[1005],dpb[1005];
int c[1005];
int fa[1005];
int fb[1005];

int n,f;
int p1,p2;

int mina=INF,minb=INF;
void Init(){
	cin>>n>>f>>p1>>p2;
	REP(i,1,n){
		cin>>c[i];
	}

	REP(i,1,n){
		cin>>fa[i];
		mina=min(mina,fa[i]);
	}

	REP(i,1,n){
		cin>>fb[i];
		minb=min(minb,fb[i]);
	}

	memset(dpa , 0 ,sizeof dpa);
	memset(dpb , 0, sizeof dpb);
	return ;
}

void Solve(){
	int ansa,ansb;
	REP(i,mina,f)
	{
		REP(j,1,n){
			if(i>=fa[j]){
				dpa[i]=max(dpa[i],dpa[i-fa[j]]+c[j]);
			}
		}

		if(dpa[i]>=p1){
			ansa=i;
			break;
		}
	}

	REP(i,minb,f){
		REP(j,1,n){
			if(i>=fb[j]){
				dpb[i]=max(dpb[i],dpb[i-fb[j]]+c[j]);
			}
		}
		if(dpb[i]>=p2){
			ansb=i;
			break;
		}
	}

	if(ansa+ansb<=f){
		print(1);
	}else{
		print(0);
	}

	return ;
}

int main(){
#ifdef LOCAL
	freopen("uoj10680.in","r",stdin);
#endif
	int t;
	scanf("%d",&t);
	while(t--)
	Init(),Solve();
	return 0;
}