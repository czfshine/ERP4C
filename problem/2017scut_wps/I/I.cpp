#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAXN = 2000 + 5;
const int P = (int)1e9 + 7;
const int INF = 2000000000 + 1;
vector<int> G[MAXN];
bool vis[MAXN];
int a[MAXN],tot;
LL f[MAXN][MAXN][2];
void dfs(int u){
	for(auto v:G[u]){
		if(vis[v]) continue;
		vis[v] = true;
		++tot;
		a[tot] = a[tot - 1];
		dfs(v);
	}
}
void init(int n){
	tot = 0;
	memset(vis,false,sizeof vis);
	for(int i=1;i<=n;++i){
		if(G[i].size() != 1 || vis[i]) continue;
		vis[i] = true;
		++tot;
		a[tot] = a[tot - 1] + 1;
		dfs(i);
	}
	while(tot < n){
		++tot;
		a[tot] = a[tot - 1] + 1;
	}
}
LL solve(int n){
	init(n);
	f[1][0][0] = 1;
	for(int i=2;i<=n;++i){
		for(int j=0;j<=i;++j){
			if(a[i] - a[i - 1] != 0){
				f[i][j][1] = 0;
				f[i][j][0] = (f[i-1][j][0] + f[i-1][j][1]) * (i-j) % P +
					(f[i-1][j+1][0] + f[i-1][j+1][1]) * (j + 1) % P;
			}
			else{
				f[i][j][0] = f[i-1][j][0] * (i-j-2) % P +
					         f[i-1][j][1] * (i-j-1) % P +
							 f[i-1][j+1][0] * (j+1) % P +
							 f[i-1][j+1][1] * j % P;
				f[i][j][1] = f[i-1][j][1];
				if(j > 0)
					f[i][j][1] += f[i-1][j-1][0] * 2 + f[i-1][j-1][1];
			}
			f[i][j][0] %= P;
			f[i][j][1] %= P;
		}
	}
	LL res = 0;
   	for(int j=1;j<=n;++j)
		res = (res + f[n][j][0] + f[n][j][1]) % P;
	return res;	
}
int main(){
//	freopen("data8.in","r",stdin);
//	freopen("data8.out","w",stdout);
	int n,m;
	scanf("%d %d",&n,&m);

	if(n<=m) cerr<<"NO\n";

	for(int i=1,u,v;i<=m;++i){
		scanf("%d %d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	printf("%lld\n",solve(n));
	return 0;
}
