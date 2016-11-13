/*

**************************************
8626 原子量计数
**************************************
Description

给出一个化学原子式，仅含有C,H,O,N 四种元素，计算其总分子量。


**************************************
Input

例如，C6H5OH 的原子量为94.108g/mol，计算方法为：

6 × (12.01 g/mol) + 6 × (1.008 g/mol) +1 × (16.00 g/mol).


**************************************
Output

输入的第一行是数字T，表示输入文件含有T个CASE。之后有T行，每行有一个长度小于100 的字符串，

表示要求的分子式。原子都用大写字母表示，没有括号，保证所有的式子都合法。


**************************************
Sample Input输出每个式子的原子量。
**************************************
Sample Output

4

C

C6H5OH

NH2CH2COOH

C12H22O11


**************************************
Hint

12.010

94.108

75.070

342.296


**************************************
Source
**************************************
Author0*/
#include "stdio.h"
#include <string.h>
#define C 12.01
#define H 1.008
#define O 16.00
#define N 14.01
//todo
int getnum(char * str,int *cur){
	int sum=0;
	for (;;)
	{	
		(*cur)++;
		printf("%d",*cur);
		if(str[*cur]>='0' &&str[*cur]<='9'){
			sum=sum*10+(str[*cur]-'0');
			

		}else{
			return sum;
		}
	}
}
int main(int argc, char const *argv[])
{
	int T;
	scanf("%d",&T);
	char str[101];
	for (int i = 0; i < T; ++i)
	{
		scanf("%s",str);

		int cur=0,len=strlen(str),n=0;
		double sum=0;
		while(cur<=len){
			switch(str[cur]){
				case 'C':n=getnum(str,&cur);sum+=n*C;break;
				case 'N':n=getnum(str,&cur);sum+=n*N;break;
				case 'H':n=getnum(str,&cur);sum+=n*H;break;
				case 'O':n=getnum(str,&cur);sum+=n*O;break;
			}
			printf("%lld",sum);
		}

		printf("%lld",sum);
	}
	return 0;
}