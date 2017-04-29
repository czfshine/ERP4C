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



typedef  pair<int,string> user;
priority_queue<user > pq;

int usernum;

void Init(){

	scanf("%d%d",&usernum);
	
	return ;
}

void Solve(){
	
	user temp;
	int ttime=-1;
	int lv;
	string name;

	user out;
	
	int outusernum=0;
	int p=0;//%5
	int ttweight=99999;
	while(usernum--){
        cin>>ttime>>lv>>name;
        
        while(ttime-p>0){
            if(!pq.empty()){
                cout<<pq.top().second<<endl;
                pq.pop();
               
            }
             outusernum++;
            p+=5;
        }
        pq.push(make_pair(lv*100000+ttweight,name));
        ttweight--;
    }

    while(!pq.empty()){
        cout<<pq.top().second<<endl;
        pq.pop();
        outusernum++;
    }

	return ;
}

int main(){
#ifdef LOCAL
	freopen("uoj18105.in","r",stdin);
#endif


	Init(),Solve();
	return 0;
}