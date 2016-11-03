#include "stdio.h"
main(){
    char str[6];
    scanf("%s",str);
    int i;
    for(i=0;i<6;i++)
        if(str[i]<123&&str[i]>64)
        	str[i]=str[i]<91?str[i]+32:str[i];
    str[5]='\0';
    printf("%s",str);
}
