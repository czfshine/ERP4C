// ━━━━━━神兽出没━━━━━━
//      ┏┓       ┏┓
//     ┏┛┻━━━━━━━┛┻┓
//     ┃           ┃
//     ┃     ━     ┃
//     ████━████   ┃
//     ┃           ┃
//     ┃    ┻      ┃
//     ┃           ┃
//     ┗━┓       ┏━┛
//       ┃       ┃
//       ┃       ┃
//       ┃       ┗━━━┓
//       ┃           ┣┓
//       ┃           ┏┛
//       ┗┓┓┏━━━━━┳┓┏┛
//        ┃┫┫     ┃┫┫
//        ┗┻┛     ┗┻┛
//
// ━━━━━━感觉萌萌哒━━━━━━

// Author        : WhyWhy
// Created Time  : 2017年04月16日 星期日 23时38分00秒
// File Name     : B.cpp

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

const int HASH=10000003;
const int MaxN=30000000;

int ccc1,ccc2;

struct HASHMAP {
	int head[HASH],next[MaxN],Hcou;
	int key1[MaxN],key2[MaxN];
	int val[MaxN];

	void init() {
		Hcou=0;
		memset(head,-1,sizeof(head));
	}

	void update(long long k1,long long k2,int v) {
		++ccc1;

		int h=(((long long)k1<<31)+k2)%HASH;

		for(int i=head[h];i!=-1;i=next[i])
			if(k1==key1[i] && k2==key2[i]) {
				val[i]=max(val[i],v);
				return;
			}

		val[Hcou]=v;
		key1[Hcou]=k1;
		key2[Hcou]=k2;
		next[Hcou]=head[h];
		head[h]=Hcou++;

		if(Hcou>=MaxN) {
			cerr<<"NONO\n";
			exit(1);
		}
	}

	int query(long long k1,long long k2) {
		++ccc2;

		int h=(((long long)k1<<31)+k2)%HASH;

		for(int i=head[h];i!=-1;i=next[i])
			if(k1==key1[i] && k2==key2[i])
				return val[i];

		return 0;
	}

}hrem;

int ran1[100],rcou1;
int ran2[100],rcou2;

inline void update(int x,int ran[],int & cou) {
	cou=0;
	x|=(1<<20);
	for(;x;x>>=1) ran[++cou]=x;
}

inline void update(int val) {
	for(int i=1;i<=rcou1;++i)
		for(int j=1;j<=rcou2;++j)
			hrem.update(ran1[i],ran2[j],val);
}

void query(int ql,int qr,int L,int R,int po,int ran[],int & cou) {
	if(ql<=L && qr>=R) {
		ran[++cou]=po;
		return;
	}

	int M=(L+R)>>1;
	if(ql<=M) query(ql,qr,L,M,po<<1,ran,cou);
	if(qr>M) query(ql,qr,M+1,R,(po<<1)|1,ran,cou);
}

inline void query(int L,int R,int ran[],int & cou) {
	cou=0;
	query(L,R,0,(1<<20)-1,1,ran,cou);
}

inline int getans() {
	int ret=0;
	for(int i=1;i<=rcou1;++i)
		for(int j=1;j<=rcou2;++j)
			ret=max(ret,hrem.query(ran1[i],ran2[j]));
	return ret;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int M;
	int t,x,y,x1,y1,v;

	while(~scanf("%d",&M)) {
		hrem.init();

		while(M--) {
			//if(M%100==0) cerr<<M<<endl;

			scanf("%d %d %d",&t,&x,&y);

			if(t==1) {
				scanf("%d",&v);
				update(x,ran1,rcou1);
				update(y,ran2,rcou2);
				update(v);
			}
			else {
				scanf("%d %d",&x1,&y1);

				query(x,x1,ran1,rcou1);
				query(y,y1,ran2,rcou2);
				printf("%d\n",getans());
			}
		}
	//cerr<<ccc1<<' '<<ccc2<<endl;
	//cerr<<clock()/1000000.0<<endl;
	}

	//cerr<<clock()/1000000.0<<endl;

	return 0;
}
