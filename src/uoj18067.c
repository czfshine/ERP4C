/*

**************************************
18067 字符统计
**************************************
Description

编写一个函数，统计一个字符串中字母、数字和空格的个数。使用全局变量存放字母和数字个数，函数返回值是空格个数
**************************************
Input

输入一行字符，以'\n'符结束
**************************************
Output

统计结果
**************************************
Sample Input

Ab 45


**************************************
Sample Output

2 2 1


**************************************
Author0*/
#include <stdio.h>
#include <string.h>
#include <math.h>

int nL=0, nN=0;

int statistics(char *s)
{
    int nS=0,i=-1,c=0;

    while(s[c]!='\0'){
        c++;
        i++;

        if(s[i]>='A'&& s[i]<='Z' ||s[i]>='a' &&s[i]<='z'){
            nL++;
            continue;
        }

        if(s[i]>='0' &&s[i]<='9'){
            nN++;
            continue;
        }

        if(s[i]==' '){
            nS++;
            continue;
        }

    }
    return nS;
}

int main()
{
    char s[81];
    int nS;
    gets(s);
    nS = statistics(s);

    printf("%d %d %d\n", nL, nN, nS);
    return 0;
}
