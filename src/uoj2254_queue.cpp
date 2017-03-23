#include <stdio.h>

main(int argc, char const *argv[])
{
	int n;
	scanf("%d",&n);
	int data[n];
	for (int i = 0; i < n; ++i)
	{
		/* code */

		scanf("%d",data+i);
	}


	int f[10000];
	int s[10000];

	char ch;
	int *p=f;
	int cur=0;
	while(scanf("%c",&ch)>0){

		if(ch=='='){
			p=s;
			cur=0;
		}

		if(ch==1){
			p[cur]=-1;
			cur++;
			break;
		}
		if(ch==0){
			p[cur]=-2;
			cur++;
			break;
		}

		for (int i = 0; i < data[ch-'a']; ++i)
		{
			p[cur]=ch*10000+i;
			cur++;
		}
	}

	for (int i = 0; i < cur; ++i)
	{
		printf("%d ",*(f+i));
	}
	return 0;
}