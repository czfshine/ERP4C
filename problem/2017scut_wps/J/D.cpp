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
// Created Time  : 2017年04月17日 星期一 00时26分22秒
// File Name     : D.cpp

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
#include <stack>

using namespace std;

const int MaxN=5000005;

struct QUE {
	int L,R,id;

	bool operator < (const QUE & b) const {
		if(L!=b.L) return L<b.L;
		if(R!=b.R) return R>b.R;
		return id<b.id;
	}
}que[100005];

inline bool cmp(const QUE & a,const QUE & b) {
	return a.id<b.id;
}

int N,P,M;
int A[MaxN];
//int del[MaxN];

map <int,int> del;

//int rpow[MaxN];

int Q;

inline long long rpow(int x) {
	long long ret=1,base=P;
	for(;x;x>>=1,(base*=base)%=M)
		if(x&1) (ret*=base)%=M;
	return ret;
}

////////////////

vector <int> E[100005];

void init(int N) {
	for(int i=1;i<=N;++i) E[i].clear();
}

inline void addEdge(int u,int v) {
	E[u].push_back(v);
}

////////////////

long long ans[100005];

inline long long merge(long long a,long long b,long long pos) {
	a%=M;
	b%=M;
	return (rpow(pos)*b%M+a)%M;
}

inline long long cal(int L,int R) {
	long long ret=0;
	for(int i=R;i>=L;--i) ret=(ret*P%M+(long long)A[i])%M;
	return ret;
}

long long dfs(int u) {
	int L=que[u].L,R=que[u].R;
	long long ret=0,pos=0,tmp;
	int len=E[u].size();

	for(int i=0;i<len;++i) {
		int v=E[u][i];

		tmp=cal(L,que[v].L-1);

		ret=merge(ret,tmp,pos);
		pos+=que[v].L-L;

		ret=merge(ret,dfs(v),pos);
		pos+=que[v].R-que[v].L+1;

		L=que[v].R+1;
	}

	tmp=cal(L,R);

	ret=merge(ret,tmp,pos);

	ans[u]=ret;
	return ret;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	long long a0,b,c,d;

	while(~scanf("%d %d %d",&N,&P,&M)) {
		scanf("%lld %lld %lld %lld",&a0,&b,&c,&d);
		A[0]=a0;
		del.clear();
		for(int i=1;i<=N;++i) A[i]=(A[i-1]*(long long)b+c)%d;

		scanf("%d",&Q);
		for(int i=1;i<=Q;++i) {
			scanf("%d %d",&que[i].L,&que[i].R);
			que[i].id=i;
			++del[que[i].R];
		}
		sort(que+1,que+Q+1);
		que[0].L=1;
		que[0].R=N;

		for(int i=1;i<Q;++i) {
			if(que[i].L<que[i+1].L) {
				if(que[i].R>=que[i+1].L && que[i].R<que[i+1].R) {
					cerr<<"NONO\n";
					exit(1);
				}
			}
		}

		stack <int> stk;
		stk.push(0);

		init(Q);
		for(int i=1,p=1;i<=Q;++i) {
			while(p<que[i].L) {
				for(int j=del[p]-1;j>=0;--j) stk.pop();
				++p;
			}

			addEdge(stk.top(),que[i].id);
			stk.push(que[i].id);
		}

		sort(que+1,que+Q+1,cmp);
		dfs(0);

		for(int i=1;i<=Q;++i) printf("%d\n",(int)ans[i]);
	}

	return 0;
}
