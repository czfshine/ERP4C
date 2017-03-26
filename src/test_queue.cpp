#include <cstdio>   
#include <functional>
#include <queue>
#include <vector>

#include <iostream>
#include <utility>
using namespace std;

typedef  pair<int,string> user;

int main(int argc, char const *argv[])
{
	priority_queue<user > pq;

	user temp;
	/*pair 的排序是按first排序的*/
	pq.push(make_pair(1,"test"));// 现在内部是[ (1,"test")]
	pq.push(make_pair(4,"tes"));// 现在内部是[ (4,"tes"),(1,"test")]
	pq.push(make_pair(3,"te"));// 现在内部是[ (4,"tes"),(3,"te"),(1,"test")]

	cout<<pq.top().second<<endl;//取第一个，是"tes"

	//删掉第一个
	pq.pop();//现在内部是[ (3,"te"),(1,"test")]

	cout<<pq.top().second<<endl;//取第一个，是"tes"
	return 0;
}