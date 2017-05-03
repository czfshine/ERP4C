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

int fa[10010],le[30],bgn[30];  

int n, a[10010],b[10010],la = 0,lb = 0;  

int find(int x)  
{  
    return (x==fa[x]?x:find(fa[x]));  
}  
  
void Union(int m, int n)
{  
    m = find(m);  
    n = find(n);  
    if(m!=n)  
        fa[m] = n;  
}  
  


void Init(){
	scanf("%d",&n);  
    scanf("%d",&le[0]);  
    bgn[0] = 2;  

    REP(i,1,n-1)
    {  
        scanf("%d",&le[i]);  
        bgn[i] = bgn[i-1] + le[i-1];  
    } 

    char ch;  
    getchar();  
    while((ch= getchar())!='=')  
        if(ch=='0' || ch=='1')  
            a[la++] = ch-'0';  
        else  
            REP(i,0,le[ch-'a']-1)
                a[la++] = bgn[ch-'a'] + i;  

    while((ch= getchar())!='\n' && (ch)!=EOF)  
        if(ch=='0' || ch=='1')  
            b[lb++] = ch-'0';  
        else  
         	REP(i,0,le[ch-'a']-1) 
                b[lb++] = bgn[ch-'a'] + i;  

	return ;
}

void Solve(){
	if(la!=lb)
    {
       print(0);
        return ;
    }
    
    REP(i,0,bgn[n-1]+le[n-1]-1)
        fa[i] = i;

    REP(i,0,la-1)
    {
        if(a[i]+b[i]==1)
        {
            print(0);
            return ;
        }

        Union(a[i],b[i]);
    }

    int ans = 0;
    REP(i,0,bgn[n-1]+le[n-1]-1)
        if(fa[i]==i) ans++;
    if(ans==0)
    	printf("WTF????\n");
   	else if(ans==1)
   		printf("FUCK!!!!\n");
   	else{
   		int a=1;
    	printf("%d\n",1<<(ans-2));
   	}
    


	return ;
}

int main(){
#ifdef LOCAL
	freopen("uoj1138.in","r",stdin);
#endif


	Init(),Solve();
	return 0;
}