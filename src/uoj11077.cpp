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

char a[1005],b[1005]; 
int m[1005][1005];
int la,lb;
int res=-1;
int mark;

void Init(){
	return ;
}

void Solve(){
	
	la=strlen(a);lb=strlen(b);

    REP(i,0,la-1)
        REP(j,0,lb-1)
            if(a[i]==b[j])
                if(i==0||j==0) 
                	m[i][j]=1;
                else 
                	m[i][j] = m[i-1][j-1]+1;
            else
            	m[i][j]=0;
    REPD(i,la-1,0)    
        REP(j,0,lb-1) 
            if(res<=m[i][j])
               {
                   res = m[i][j];
                   mark = i;
               }

    cout << res<< endl;
    REP(i,mark-res+1,mark)
       cout << a[i];
	return ;
}

int main(){

	freopen("uoj11077.in","r",stdin);

	IOS;
	cin >> a >> b;

	Init(),Solve();
	return 0;
}