/*

**************************************
18045 前一个和后一个字符
**************************************
Description

编写程序，输入一个数字字符，输出其前一个和后一个的数字字符，如果输入的是0前一个输出

“first”，9后一个则输出“last”，输入的不是数学字符，输出“error”
**************************************
Input

一个字符
**************************************
Output

输出结果
**************************************
Sample Input

0
**************************************
Sample Output

first 1
**************************************
Author0*/
#include "stdio.h"
int main(int argc, char const *argv[])
{
	char ch;
	ch=getchar();
	if(ch<'0' || ch >'9'){
		printf("error");
	}else{
		switch(ch){
			case '0':{
				printf("first 1");//fuck !!!!
				break;
			}
			case '9':
			{
				printf("8 last");
				break;
			}
			default :
				printf("%c %c",ch-1,ch+1);
		}
	}
	return 0;
}