#include <cstdio>
#include <cstdlib>
#include <iostream>
#define  MAXSTRLEN  255                   // 用户可在255以内定义最大串长
typedef unsigned char SString[MAXSTRLEN+1];	// 0号单元存放串的长度

void get_next(SString T,int next[]){

	int i,j;
	next[1]=0;
	j=0;

	while(i<T[0]){	
		

		if(j == 0 || T[i]==T[j]){
			++i;
			++j;
			next[i]=j;  
		}

		else{
			j=next[j];	
		}

	}
}
int  main(){
	int next[MAXSTRLEN];
	SString S;
	int n,i,j;
	char ch;
	scanf("%d",&n);    // 指定要验证NEXT值的字符串个数
	ch=getchar();
	for(i=1;i<=n;i++)    
	{
		ch=getchar();
		for(j=1;j<=MAXSTRLEN&&(ch!='\n');j++)    // 录入字符串
		{
			S[j]=ch;
			ch=getchar();
		}
		S[0]=j-1; 
		S[j]=0;   // S[0]用于存储字符串中字符个数
		printf("%s\n",S+1);
		get_next(S,next);
		printf("%d",j);     
		printf("NEXT J is:");
		for(j=1;j<=S[0];j++)
			printf("%d\n",next[j]);
		printf("\n");
	}
}

