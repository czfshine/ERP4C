#include "stdio.h"
#include "math.h"
#include "string.h"
#include "stdlib.h"
#include "ctype.h"
char words[10001][21]= {0},tmp_w[21]; //keys
int  count[10001]= {0}, lcur=0,t=0,cur=0;    //values
int next(FILE * infile,char * word)//得到下一个单词
{
    char ch,i=0;
    while((ch=getc(infile))!=EOF)
        if(isalpha(ch)) 
        	word[i++]=tolower(ch);
        else
        {
            if(ch=='-')
                if((ch=getc(infile))=='\n') 
                	continue;
                else 
                	fseek(infile,-1L,SEEK_CUR);
            word[i]='\0';
            return 1;
        }
    return 0;
}
void counter(char * word)//计数
{
    int i=0;
    if(lcur>2&&strcmp(words[lcur-1],word)==0) 
    	cur= lcur-1;
    else
    {
        while(words[i][0]!='\0' &&(strcmp(words[i++],word)!=0 )) {}
        cur= (words[i][0]=='\0')?-1:i-1;
    }
    if(cur!=-1) 
    	count[cur]++;
    else
    {
        count[lcur]=1;
        strcpy(words[lcur++],word);
    }
}
main()
{
    FILE * infile;
    infile=fopen("case1.in","r");
    while(next(infile,tmp_w)) 
    	if(strlen(tmp_w)>0) 
    		counter(tmp_w);

    for(int i=0; i<lcur&&i<5; i++,t=0)//输出
    {
        for(int j=0; j<lcur; j++)
            if(count[j]>count[t]||(count[j]==count[t]&&strcmp(words[j],words[t])<0)) 
            	t=j;
        (strlen(words[t])>0)?printf("%s %d\n",words[t],count[t]):i--;
        count[t]=0;
    }
}
