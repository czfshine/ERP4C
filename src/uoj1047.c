#include "stdio.h" 
main() 
{  int a[10], i, j, t; 
   for(i=0;i<10;i++) 
      scanf("%d",a+i) ;     
   for(i=0;i<10;i++) 
   {     for(j=0;j<i;j++) 
         if (a[i]<a[j]) 
            {t=a[i];a[i]=a[j];a[j]=t;} 
   } 
   for(i=0;i<10;i++) 
      printf("%d ",a[i]); 
} 

