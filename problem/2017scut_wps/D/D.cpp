#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAXN = 205;
const int P = (int)1e9 + 7;
LL jie[MAXN];
LL c[MAXN][MAXN];
LL f[MAXN][MAXN];
bool is_prime(int x){
	for(int i=2;i*i<=x;++i){
		if(x % i == 0)
			return false;
	}
	return true;
}
void init(const int n){
	jie[0] = 1;
	for(int i=1;i<=n;++i)
		jie[i] = jie[i - 1] * i % P;
	for(int i=0;i<=n;++i){
		for(int j=0;j<=i;++j){
			c[i][j] = j == 0 ? 1 : (c[i - 1][j] + c[i - 1][j - 1]) % P;
		}
	}
}
LL solve(const int n,const int m){
	init(n);
	int s = 0;
	for(int i=2;i<=n;++i){
		if(is_prime(i))
			++s;
	}
	memset(f,0,sizeof f);
	for(int i=1;i<=n;++i){
		for(int j=0;j<=s;++j){
			LL tmp = 0;
			for(int k=1;k<=j;++k)
				(tmp += c[j][k] * f[i - k][j - k] % P) %= P;
			f[i][j] = (jie[i] - tmp + P) % P;
		}
	}	
	return f[n - m][s - m] * c[s][m] % P;
}
int main(){
	freopen("data8.in","r",stdin);
	freopen("data8.out","w",stdout);
	int n,m;
	while(~scanf("%d %d",&n,&m)){
		printf("%d\n",(int)solve(n,m));
	}
	return 0;
}
