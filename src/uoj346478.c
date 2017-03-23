#include <stdio.h>

int main(int argc, char const *argv[])
{
	int n,s,m;
	scanf("%d%d%d",&n,&s,&m);
	char data[n];

	for (int i = 0; i < n; ++i)
	{
		//n 写错
		data[i]=1;
	}
	if(m==1){
		for (int i = s; i <= n; ++i)
		{
			printf("%d ",i);
		}
		for (int i = 1; i < s; ++i)
		{
			printf("%d ",i);
		}
		return 0;
	}
	int l=0,d=1,cur;
	l=n;
	cur=s-1;
	while(l>=1){

		for(;;){
			if(data[(cur+1)%n]){
				d++;
				if((d%m)==0){
					data[(cur+1)%n]=0;
					printf("%d ",(cur+1)%n+1);
					cur=(cur+1)%n;
					l--;
					break;
				}

			}
			cur=(cur+1)%n;
		}
	}

	//printf("%d",data[(cur+1)%n]);
	return 0;
}