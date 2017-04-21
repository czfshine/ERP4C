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



const int maxw=50000;
double dp[maxw+10];

struct node
{
    int a,b;
    bool operator <(const node t) const
    {
        return 1.0*b/a>1.0*t.b/t.a;//单价最高的
    }
}wa[110],st[110];

double Greed(int n,int w)
{
    double sum=0;
    int i=0;
    while(w&&i<n)
    {
        if(w>=wa[i].a)//从单价最高的开始取，取到不能全部放入
        {
            sum+=wa[i].b;
            w-=wa[i++].a;
        }
        else//不能全部放入就放满
        {
            sum+=w*1.0*wa[i].b/wa[i].a;
            w=0;
        }
    }
    return sum;
}

int n,w;
int c,i,l=0,r=0;

void Init(){

	memset(dp,0,sizeof(dp));

	for(i=0;i<n;i++)
    {
        scanf("%d%d%d",&st[l].a,&st[l].b,&c);
        if(c)
            wa[r++]=st[l];
        else
            l++;
    }
    sort(wa,wa+r);
	return ;
}

void Solve(){

	//先全部放水
	REP(i,1,w)
        dp[i]=Greed(r,i);

    //01背包咯
    REP(i,0,l-1)
        REPD(j,w,st[i].a)
            dp[j]>?= (dp[j-st[i].a]+st[i].b);

    printf("%.2lf\n",dp[w]);
	return ;
}

int main(){

	freopen("uoj9513.in","r",stdin);


	while(~scanf("%d%d",&n,&w))
	Init(),Solve();
	return 0;
}