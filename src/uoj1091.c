/*

**************************************
1091 [填空]交换两数，由大到小输出
**************************************
Description
下面程序，交换两数，使两数由大到小输出，请填空
**************************************
Sample Input
1 2
**************************************
Sample Output
2 1
**************************************
Author0*/
#include "stdio.h" 

void swap(int* p1,int* p2)           
{   
   int temp; 
   temp=*p1; 
   *p1=*p2; 
   *p2=temp;  
}  

int main()                                                 
{ int a,b; int *pa,*pb; 
   scanf("%d%d", &a, &b); 
   pa=&a; pb=&b; 
  if(a<b) swap(pa,pb); 
  printf("%d %d\n",a,b); 
}  