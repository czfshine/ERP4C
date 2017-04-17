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




void Init(){


	return ;
}

void Solve(int t){
	int n;
	scanf("%d",&n);

	int a=n*n;

	REPD(i,2051,3){

		int b=i*i;

		int k1=sqrt(a+b);
			if(k1*k1==a+b&& k1>0 && i>=k1){
				printf("%d %d\n",i,k1);
			}
		int k2=sqrt(a-b);
			if(k2*k2+b==a&& k2>0 && i>=k2){
				printf("%d %d\n",i,k2);
			}
		int k3=sqrt(b-a);
			if(k3*k3+a==b&& k3>0 && i>=k3){
				printf("%d %d\n",i,k3);
			}
	}
	if(t>1) printf("\n");

	return ;
}

int main(){

	freopen("uoj1079.in","r",stdin);


	int t;
	scanf("%d",&t);
	while(t--)
	Init(),Solve(t);
	return 0;
}