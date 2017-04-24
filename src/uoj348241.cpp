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
int r[20];
int d[2][30];
int cnt,n;
void dfs(int cur)
{
    if(cur==n+1)
    {
        cnt++;
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(!r[i]&&!d[0][cur+i]&&!d[1][cur-i+n])
        {
            r[i]=d[0][cur+i]=d[1][cur-i+n]=1;
            dfs(cur+1);
            r[i]=d[0][cur+i]=d[1][cur-i+n]=0;




        }
    }

}

void Init(){
	memset(r,0,sizeof(d));
    memset(d,0,sizeof(d));

	return ;
}

void Solve(){
	scanf("%d",&n);
        cnt=0;
        dfs(1);
        printf("%d\n",cnt);

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