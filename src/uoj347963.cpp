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


string i;


void Init(){

	cin>>i;
	return ;
}

void Solve(){
	
	int len=i.size();
	int ans=0;

	REP(k,1,len/2){

		if(i[k-1]!='#')
			if((i[2*k-1]=='#' && i[2*k] !='#')||(i[2*k-1]!='#' && i[2*k] =='#'))
				{cout<<i[k-1]<<i[2*k-1]<<i[2*k]<<endl;
					ans++;

				}



				
		

	}
	cout<<ans<<endl;
	return ;
}

int main(){

	freopen("uoj347963.in","r",stdin);

	Init(),Solve();
	return 0;
}