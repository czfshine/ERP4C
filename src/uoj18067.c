#include <stdio.h>
#include <string.h>
#include <math.h>

int nL=0, nN=0;

int statistics(char *s)
{
    int nS=0,i=-1,c=0;

    while(s[c]!='\0'){
        c++;
        i++;

        if(s[i]>='A'&& s[i]<='Z' ||s[i]>='a' &&s[i]<='z'){
            nL++;
            continue;
        }

        if(s[i]>='0' &&s[i]<='9'){
            nN++;
            continue;
        }

        if(s[i]==' '){
            nS++;
            continue;
        }

    }
    return nS;
}

int main()
{
    char s[81];
    int nS;
    gets(s);
    nS = statistics(s);

    printf("%d %d %d\n", nL, nN, nS);
    return 0;
}
