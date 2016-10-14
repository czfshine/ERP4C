#include "stdio.h"

void yuan(char *s,char *s2)
{   int i,k=0;
    for(i=0;i<81;i++){
        if(s[i]=='\0')
        break;
        switch(s[i]){
            case'a':
            case'e':
            case'i':
            case'o':
            case'u':
            case'A':
            case'E':
            case'I':
            case'O':
            case'U':{s2[k]=s[i];k++;break;}
        }
    }
    s2[k]='\0';
}

main()
{
    char str[81], str2[81];
    gets(str);
    yuan(str,str2);
    printf("%s", str2);
}
