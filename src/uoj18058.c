/*

**************************************
18058 一年的第几天
**************************************
Description

定义一个结构体类型表示日期类型（包括年、月、日）。程序中定义一个日期类型的变量，输入该日期的年、月、日，

计算并输出该日期是一年的第几天。
**************************************
Input

年月日，格式如样例
**************************************
Output

该年的第几天
**************************************
Sample Input

2015-1-1
**************************************
Sample Output

1
**************************************
Author0*/
#include <stdio.h>

struct DATE
{
    int year;
    int month;
    int day;
};

int days(struct DATE date)
{
    int days[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    int day=0,i;

    if(date.year%4==0 && date.year%100!=0 || date.year%400 ==0){
        days[1]=29;
    }
    for(i=0;i<date.month-1;i++){
        day+=days[i];
    }
    day+=date.day;

    return day;
}

int main()
{
    struct DATE d;
    scanf("%d-%d-%d", &d.year, &d.month, &d.day);
    printf("%d", days(d));
}
