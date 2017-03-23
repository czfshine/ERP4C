#include <stdio.h>
int main(int argc, char const *argv[])
{
	int n,s,m;

	scanf("%d %d %d",&n,&s,&m);
	char data[n];

	for (int i = 0; i < n; ++i)
	{
		data[i]=1;
	}

	int l=0,d=1 ,cur;

	l=n;
	cur=s-1;

	while(l>=1){
		int now=(cur+1)%n;
		for(;;){
			
			if(data[now]){
				d++;
				if((d%m)==0){
					data[now]=0;
					printf("%d ",now+1);
					cur=now;
					l--;
					break;

				}
			}
			cur=now;
		}
	}
	return 0;
}