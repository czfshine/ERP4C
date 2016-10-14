#include <stdio.h>

void removeSpace(char *s)
{
    char cache[81]="";
    int i=0,k=0;
    while(s[i]!='\0'){
        if(s[i]!=' '){
            cache[k]=s[i];
            k++;
        }
        i++;
    }
    for(i=0;i<81;i++){
        s[i]=cache[i];
    }
    s[80]='\0';
}

int main()
{
    char s[81];
    gets(s);
    removeSpace(s);
    printf("%s", s);
    return 0;
}
