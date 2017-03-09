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
	
	int l=0,d=1,cur;
	l=n;
	cur=s-1;
	while(l>=1){

		for(;;){
			if(data[(cur+1)%n]){
				d++;
				if((d%m)==0){
					data[(cur+1)%n]=0;
					if(l==1)printf("%d",(cur+1)%n+1);
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