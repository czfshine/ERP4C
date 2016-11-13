/*

**************************************
1031 统计单词个数
**************************************
Description

写一个函数实现：输入一行字符，以空格分割单词，回车结束输入，输出单词的个数
**************************************
Sample Input

There are many students and many trees!
**************************************
Sample Output

7
**************************************
Author0*/
#include "stdio.h"
int main(int argc, char const *argv[])
{	char ch;
	char yes=0;
	int count=0;
	while((ch=getchar())!='\n'){
		if(ch==' ') {if(yes){}else{count++;yes=1;}}else{yes=0;}
	}
	printf("%d",count+1);
	return 0;
}