#include <iostream>
#include <queue>
#include <utility>
#include <stdio.h>
#include <vector>

using namespace std;
typedef  pair<long long ,long long> node;
long long re[1300];
int re1[1300]={0},i=0,T,num;;
int main(int argc, char const *argv[])
{
	priority_queue<node ,vector<node> ,greater<node> > pq;
	node n;
	pq.push(node(1,2));
	while(i<1200){

		n=pq.top();
		pq.pop();
		switch(n.second){
			case 2:pq.push(node(n.first*2,2));
			case 3:pq.push(node(n.first*3,3));
			case 5:pq.push(node(n.first*5,5));
		}
		re[i++]=n.first;

	}
	for (int i = 1; i < 1200; ++i)
		re1[i+1]=re1[i]+(re[i+1]-re[i]-1);
	i=0;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&num);
		while(re1[i]<num) i++;
		printf("%d\n",i+num);
	}
	return 0;
}