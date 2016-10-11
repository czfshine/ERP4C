#include "stdio.h" 
main() 
{  int a[20], i, j, t,count=0; 
   for(i=0;i<20;i++) 
      scanf("%d",a+i) ;     
   for(i=0;i<20;i++) 
   {     for(j=0;j<i;j++) 
         if (a[i]<a[j]) 
            {t=a[i];a[i]=a[j];a[j]=t;} 
   } 
   if(a[0]==a[1]) count++;
   for(i=0;i<20;i++) 
      if(a[i-1]!=a[i]) 
      	count ++;
   printf("%d",count);
} 