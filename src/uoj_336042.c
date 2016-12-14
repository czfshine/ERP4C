#include "stdio.h" 

main() 
{ 
    FILE *fp; 
    char ch; 

    if((fp=fopen("case1.in","r"))==NULL) 
        return 0; 
    while((ch=getc(fp))!=EOF) 
    { 
        if(ch>='0'&&ch<='9') putchar(ch);
    } 
    fclose(fp); 
}