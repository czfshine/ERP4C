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

char s[1000005],t[10005];    
int p[10005];    

void Init(){
	scanf("%s%s",t,s);

	return ;
}

#define diff(str,tem,i,j) while(j&&str[i]!=tem[j])j=p[j];
void Solve(){
	
	int n=strlen(s);
    int m=strlen(t);
    int i,j,ans=0;
    p[0]=p[1]=0;
    REP(i,1,m-1){
        j=p[i];
        diff(t,t,i,j)
        p[i+1]=t[i]==t[j]?j+1:0;
    }
    j=0;
    REP(i,0,n){
        diff(s,t,i,j)
        if(s[i]==t[j])j++;
        if(j==m)ans++;
    }
    printf("%d\n",ans);
	return ;
}

int main(){
#ifdef LOCAL
	freopen("hdu1686.in","r",stdin);
#endif

	int T;
    scanf("%d",&T);
    while(T--)
	Init(),Solve();
	return 0;
}