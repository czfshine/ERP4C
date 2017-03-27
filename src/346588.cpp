#include <iostream>
#include <queue>
#include <utility>

using namespace std;
typedef  pair<int,int> node;


int re[1000000];
int main(int argc, char const *argv[])
{
	priority_queue<node> pq;

	pq.push(make_pair(1,2));
	node n;
	while(1){

		node n=pq.top();

		pq.pop();

		switch(n.second){
			case 2:
				pq.push(make_pair(n.first*2,3));
			break;
			case 3:
				pq.push(make_pair(n.first*3,5));
			break;
			case 5:
				pq.push(make_pair(n.first*5,0));
			break;
		}

	}
	return 0;
}