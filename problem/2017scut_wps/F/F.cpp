#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAXN = 10000500;
int mu[MAXN];
bool check[MAXN];
int prime[MAXN];
void init(){
	int tot = 0;
	mu[1] = 1;
	memset(check,false,sizeof(check));
	for(int i=2;i<MAXN;++i){
		if(!check[i]){
			prime[tot++] = i;
			mu[i] = -1;
		}
		for(int j=0;j<tot && (LL)prime[j] * i < MAXN;++j){
			check[i * prime[j]] = true;
			if(i % prime[j] == 0){
				mu[i * prime[j]] = 0;
				break;
			}
			else
				mu[i * prime[j]] = -mu[i];
		}
	}
}
LL solve(LL n){
	LL res = 0;
	LL ma = (LL)sqrt(n + 0.5);
	for(LL i=1;i<=ma;++i){
		res += n / (i * i) * mu[i];
	}
	return res;
}
int main(){
	freopen("data8.in","r",stdin);
	freopen("data8.out","w",stdout);
	init();
	LL n;
	while(cin >> n){
		cout << solve(n) << endl;
	}
	return 0;
}
