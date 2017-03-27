#include <iostream>
#include <queue>
#include <utility>
#include <stdio.h>
#include <vector>
using namespace std;
typedef  pair<long long ,long long> node;
long long re[1300];
int re1[1300]={0};
int main(int argc, char const *argv[])
{
	priority_queue<node ,vector<node> ,greater<node> > pq;
	pq.push(node(1,2));
	node n;

	int i=0,T,num;
	while(i<1200){

		node n=pq.top();
		pq.pop();

		switch(n.second){
			case 2:pq.push(node(n.first*2,2));
			case 3:pq.push(node(n.first*3,3));
			case 5:pq.push(node(n.first*5,5));
		}
		re[i++]=n.first;
	}

	scanf("%d",&T);

	for (int i = 1; i < 1200; ++i)
		re1[i]=re1[i-1]+(re[i]-re[i-1]-1);

	i=0;
	while(T--){
		scanf("%d",&num);
		while(re1[i]<num)
			i++;
		printf("%d\n",i+num);
	}
	return 0;
}
