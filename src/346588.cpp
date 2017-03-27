#include <iostream>
#include <queue>
#include <utility>
#include <stdio.h>
#include <vector>
using namespace std;
typedef  pair<long long ,long long> node;


long long re[1300];
int main(int argc, char const *argv[])
{
	priority_queue<node ,vector<node> ,greater<node> > pq;

	pq.push(node(1,2));
	node n;
	int i=0;
	while(i<1200){

		node n=pq.top();
		//printf("%d",i);
		pq.pop();
		switch(n.second){
			case 2:
				pq.push(node(n.first*2,2));

			case 3:
				pq.push(node(n.first*3,3));

			case 5:
				pq.push(node(n.first*5,5));
		}
		re[i++]=n.first;
	}
	int T;
	scanf("%d",&T);
	int re1[1300]={0};
	for (int i = 1; i < 1200; ++i)
	{
		re1[i]=re1[i-1]+(re[i]-re[i-1]);
		printf("%d\n",re1[i]);
	}
	while(T--){
		int num;
		scanf("%d",num);
		i=0;
		while(re1[i]<num){
			i++;
		}
		printf("%d\n",re1);

	}
  
	return 0;
}
