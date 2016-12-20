#include "stdio.h" 
#include "math.h" 
#include "string.h" 
#include "stdlib.h" 
#include "ctype.h"
char words[10001][21]={0}; //keys
int  count[10001]={0}, lindex=0,t=0;     //values
int next(FILE * infile,char * word){
	char ch,i=0;
	while((ch=getc(infile))!=EOF)
		if(isalpha(ch))
			word[i++]=tolower(ch);
		else if(ch=='-')
			if((ch=getc(infile))=='\n')
				continue;
			else{
				fseek(infile,-1L,SEEK_CUR);
				word[i]='\0';
				return 1;
			}
		else {
			word[i]='\0';
			return 1;
		}
	return 0;
}
int canfind(char * word ){
	int i=0;
	if(lindex>2&&strcmp(words[lindex-1],word)==0)
		return lindex-1;
	while(words[i][0]!='\0' &&(strcmp(words[i++],word)!=0 )){}
	return (words[i][0]=='\0')?-1:i-1;
}
void counter(char * word){
	int index=0;
	if((index=canfind(word))!=-1)
		count[index]++;
	else{
		count[lindex]=1;
		strcpy(words[lindex++],word);
	}
}
main() 
{ 
	char tmp_w[21];
	FILE * infile;
	infile=fopen("case1.in","r");
	while(next(infile,tmp_w))
		if(strlen(tmp_w)>0)
			counter(tmp_w);
	for(int i=0; i<lindex&&i<5; i++,t=0) //输出已有单词中前5个最多的单词
    {
        for(int j=0; j<lindex; j++)
        {
            if(count[j]>count[t]) t=j;
            else if(count[j]==count[t])
            {
                if(strcmp(words[j],words[t])<0) t=j;
            }
        }
        
        (strlen(words[t])>0)?printf("%s %d\n",words[t],count[t]):i--;
        count[t]=0;
    }
} 