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
// Created Time  : 2017年04月17日 星期一 00时06分27秒
// File Name     : C.cpp

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

const int MaxN=100005;

int N,K;
map <int,int> rem;

int LL[MaxN],RR[MaxN],val[MaxN];
int cou;

char ans[MaxN];

inline void erase(int p) {
	RR[LL[p]]=RR[p];
	LL[RR[p]]=LL[p];
}

inline void insert(int p) {
	RR[p]=RR[0];
	LL[p]=0;

	LL[RR[0]]=p;
	RR[0]=p;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a,b;

	while(~scanf("%d %d",&N,&K)) {
		cou=0;
		RR[0]=K+1;
		LL[K+1]=0;
		rem.clear();
		ans[N]=0;

		for(int i=0;i<N;++i) {
			scanf("%d",&a);

			if(rem.count(a)) {
				ans[i]='1';

				b=rem[a];
				erase(b);
				insert(b);
			}
			else {
				ans[i]='0';

				if(cou<K) {
					++cou;
					rem[a]=cou;
					val[cou]=a;
					insert(cou);
				}
				else {
					b=LL[K+1];
					rem.erase(val[b]);
					rem[a]=b;

					erase(b);
					val[b]=a;
					insert(b);
				}
			}
		}
		puts(ans);
	}

	return 0;
}
