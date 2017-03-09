/*

**************************************
1084 [填空题]十进制数转二进制数
**************************************
Description

下面程序，实现由键盘输入一个正整数(不大于100000000)，输出其对应的二进制数（原码表示）。

请填空：


**************************************
Sample Input

12
**************************************
Sample Output

1100
**************************************
Author0*/
#include "stdio.h" 
//23333333333333333333333
void binary(long long n){
  	char b[32]={0};
    sprintf(b,"%o",n);
    int cur=0;
    switch(b[cur]){
    		case'0':printf("");break;
    		case'1':printf("1");break;
    		case'2':printf("10");break;
    		case'3':printf("11");break;
    		case'4':printf("100");break;
    		case'5':printf("101");break;
    		case'6':printf("110");break;
    		case'7':printf("111");break;
    	}
    cur++;
    while(b[cur]!='\0'){
    	switch(b[cur]){
    		case'0':printf("000");break;
    		case'1':printf("001");break;
    		case'2':printf("010");break;
    		case'3':printf("011");break;
    		case'4':printf("100");break;
    		case'5':printf("101");break;
    		case'6':printf("110");break;
    		case'7':printf("111");break;
    	}
    cur++;
    }
}

main() 
{ 
    long long n; 
    scanf("%ld64", &n); 
    binary(n); 
} 