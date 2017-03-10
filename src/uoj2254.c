#include <stdio.h>
#include <queue>
#include <vector>
char name[100000][20];
char u[100000];
char ed[100000];


struct user
{
	char name[20];
	char num;
};

struct cmp{
	bool operator() (user A,user B){
		return A.num>B.num;
	}
}

int main(int argc, char const *argv[])
{
	priority_queue<user,vector<user>,cmp> pq;
	int n;
	scanf("%d",&n);

	int maxmin;
	scanf("%d",&maxmin);

	int usern;
	if (maxmin/5){

		usern=(maxmin/5) +1;
	}else
	{
		usern=maxmin/5;
	}


	for (int i = 0; i < maxmin; ++i)
	{
		
	}
	return 0;
}