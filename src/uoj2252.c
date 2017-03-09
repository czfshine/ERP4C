#include <stdio.h>

int is(char * num,int * p){

	while(*num){

		if(*(p+((*num)-'0'))){
			return 1;
		}
	}

	return 0;
}
int main(int argc, char const *argv[])
{
	int n,m;
	scanf("%d",&n);
	int data1[n];

	for (int i = 0; i < n; ++i)
	{
		scanf("%d",data1+i);
	}

	int pA[10]={0};
	for (int i = 0; i < n; ++i)
	{
		pA[data1[i]]=1;
	}
	scanf("%d",&m);
	int data2[m];

	for (int i = 0; i < m; ++i)
	{
		scanf("%d",data2+i);
	}

	int pB[10]={0};
	for (int i = 0; i < m; ++i)
	{
		pB[data2[i]]=1;
	}


	int T;
	scanf("%d",&T);

	char po[T][64];
	for (int i = 0; i < T; ++i)
	{
		scanf("%s",po+i);
	}

	int numA=0,numB=0;
	while(T--){
		int A=(is(po[T],pA));
		int B=(is(po[T],pB));

		if(A&&B){}
			else{
				if(A){
					numA++;
				}
				if(B){
					numB++;
				}
			}
			
	}

	printf("%d\n%d",numA,numB);
	return 0;
}