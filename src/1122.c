#include "stdio.h"
#include "string.h"
main()
{
    char s[100]="";
    char a[30];
    int cur=0;
    int i,j,c=0;
    char ch;
    for(i=0;i<3;i++)  {
        while((ch=getchar())!='\n'){
            a[c++]=ch;
        }
        a[c]='\0';
        c=0;
        for (j=0;j<strlen(a);j++){
            s[cur++]=a[j];
        }
    }
    s[cur] ='\0';
    printf("%s", s);
}

