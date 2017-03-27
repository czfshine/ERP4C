#include <iostream>
#include <queue>
#include <utility>
#include <stdio.h>
#include <vector>
using namespace std;
typedef  pair<long long ,long long> node;


long long re[1000000];
int main(int argc, char const *argv[])
{
	priority_queue<node ,vector<node> ,less<node> > pq;

	pq.push(node(1,2));
	node n;
	int i=0;
	while(i<100){

		node n=pq.top();
		//printf("%d",i);
		pq.pop();
		switch(n.second){
			case 2:
				pq.push(node(n.first*2,3));

			case 3:
				pq.push(node(n.first*3,5));

			case 5:
				pq.push(node(n.first*5,5));
		}
		re[i++]=n.first;
	}
	for (int j = 0; j < i; ++j)
	{
		printf("%d\n",re[j]);
	}
    
	return 0;
}
