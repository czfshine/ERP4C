#include "stdio.h"
#define ADDC c=(c+1)%3
#define AD cur=(cur+1)%n
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d",&n);

	int data[n],p=2,cur=0;
	char c=0;
	p=n;
	for (int i = 0; i < n; ++i)
	{
		data[i]=1;
	}
	if(n==1) {printf("1");return 0;}
	if(n==2) {printf("2");return 0;}
	while(p>=1){

		if(data[cur]){
			if((ADDC)==0){
				//printf("%d\n",cur+1);
				data[cur]=0;
				p--;
			}
		}
		AD;
	}
	printf("%d" ,cur);
	return 0;
}