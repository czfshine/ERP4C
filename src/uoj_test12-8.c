#include "stdio.h" 

main() 
{ 
    FILE *fp; 
    char ch; 

    if((fp=fopen("case.in","r"))==NULL) 
        return 0; 
    while((ch=getchar(fp))!=EOF) 
    { 
        if ('A'<=ch && ch<='Z') 
            ch = ch + 32; 
        putchar(ch); 
    } 
    fclose(fp); 
}