#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAXN = 1000000 + 50;
const int P = (int)1e9 + 7;
int g[MAXN];
int prime[78500];
bool check[MAXN];
int f[MAXN][32];
void init(int n){
	memset(check,false,sizeof(check));
	int tot = 0;
	g[1] = 0;
	for(int i=2;i<=n;++i){
		if(!check[i]){
			prime[tot++] = i;
			g[i] = 1;
		}
		for(int j=0;j<tot && (LL)prime[j] * i <= n;++j){
			check[i * prime[j]] = true;
			g[i * prime[j]] = g[i] + 1;
			if(i % prime[j] == 0) break;
		}
	}
//	printf("tot = %d\n",tot);
}
LL solve(int n){
	init(n);
	f[0][0] = 1;
	int ma = 32;
	for(int i=1;i<=n;++i){
		for(int j=0;j<ma;++j){
			LL tmp = (f[i - 1][j] + f[i - 1][j ^ g[i]]) % P;
			f[i][j] = tmp;
		}
	}
	LL res = 0;
	for(int j=1;j<ma;++j)
		(res += f[n][j]) %= P;
	return res;
}
int main(){
	freopen("data12.in","r",stdin);
	freopen("data12.out","w",stdout);
	int n;
	scanf("%d",&n);
	printf("%lld\n",solve(n));
	return 0;
}
