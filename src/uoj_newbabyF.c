#include "stdio.h"
#include "string.h"
#define min(x,y) x<y?x:y
char  str[31];
int end=0;
int vis[31][31]={0};


void print(int s,int e){

	for (int i = s; i <= e; ++i)
	{
		putchar(str[i]);
	}

	printf("\n");
}
int find(int s){
	//print(s,e);
	//printf("%d %s\n",s,str+s);
	if(s==end) return 1+1;//print("%s",str+s);
	for (int i = s+1; i < (min(end,s+6)); ++i)
	{	if(!vis[s][i]){print(s,i);
		vis[s][i]=find(i);}
	}
	if(end-s>6)
		vis[s+6][end]=find(s+6);

	return 1;
}
int main(int argc, char const *argv[])
{	
	scanf("%s",str);
	end=strlen(str)-1;
	find(0);

	return 0;
}