/*
描述
输入正整数x和n，编写递归函数求x的n次方。

#include <stdio.h> 

int F(int x, int n) 
{ 
    if(_______________________) return _______________________; 
    else return _______________________; 
} 

int main() 
{ 
    int x, n; 
    scanf("%d%d", &x, &n); 
    printf("%d", F(x, n)); 
    return 0; 
} 
输入格式
两个正整数，x和n
输出格式
x的n次方，假定结果不会超过10的次方。
输入样例
5 2
输出样例
25*/
#include <stdio.h> 

int F(int x, int n) 
{ 
    if(n==1) return x; 
    else return x*F(x,n-1); 
}

int main() 
{ 
    int x, n; 
    scanf("%d%d", &x, &n); 
    printf("%d", F(x, n)); 
    return 0; 
} 
