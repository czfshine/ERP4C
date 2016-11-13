/*

**************************************
18061 数的交换
**************************************
Description

输入10个整数，把其中最小的数与第一个数交换，最大的数与最后一个数交换。使用3个函数解决问题：

(1) 输入10个整数的函数

(2) 进行交换处理的函数

(3) 输出10个数的函数


**************************************
Input

输入10个整数
**************************************
Output

输出结果，一行一个数字
**************************************
Sample Input

2 1 3 4 5 6 7 8 9 0


**************************************
Sample Output

input done

swap done

0

1

3

4

5

6

7

8

2

9

display done


**************************************
Author0*/
#include <stdio.h> 

void input(int a[]) 
{ 
    int i; 
    for(i=0; i<10; i++) 
        scanf("%d", a+i); 
} 

void swap(int a[]) 
{ 
    int minn=0,min,i;
    min=a[0];
    for(i=0; i<10; i++) {
        if(a[i]<min){
            minn=i;
        }
    }
    int maxn=0,max;
    max=a[0];
    for(i=0; i<10; i++) {
        if(a[i]>max){
            maxn=i;
        }
    }
    a[0]=a[0]+a[minn];
    a[minn]=a[0]-a[minn];
    a[0]=a[0]-a[minn];
    a[9]=a[9]+a[maxn];
    a[maxn]=a[9]-a[maxn];
    a[9]=a[9]-a[maxn];


} 

void display(int a[]) 
{ 
    int i; 
    for(i=0; i<10; i++) 
        printf("%d\n", a[i]); 
} 

int main() 
{ 
    int a[10]; 
    input(a); 
    printf("input done\n"); 
    swap(a); 
    printf("swap done\n"); 
    display(a); 
    printf("display done\n"); 
    return 0; 
} 
