#include "stdio.h"
#include "math.h"
#include "string.h"
#include "stdlib.h"
#include "ctype.h"
char words[10001][21]= {0},tmp_w[21]; //keys
int  count[10001]= {0}, lindex=0,t=0;    //values
int next(FILE * infile,char * word){
    char ch,i=0;
    while((ch=getc(infile))!=EOF)
        if(isalpha(ch)) word[i++]=tolower(ch);
        else{
        	if(ch=='-')
            	if((ch=getc(infile))=='\n') continue;
            	else fseek(infile,-1L,SEEK_CUR);
			word[i]='\0';
           	return 1;
    	}
    return 0;
}
int canfind(char * word ){
    
    
}
void counter(char * word){
	int i=0,index=0;
	if(lindex>2&&strcmp(words[lindex-1],word)==0) index= lindex-1;
    else {while(words[i][0]!='\0' &&(strcmp(words[i++],word)!=0 )) {}
    index= (words[i][0]=='\0')?-1:i-1;}
    if(index!=-1) count[index]++;
    else{
        count[lindex]=1;
        strcpy(words[lindex++],word);
    }
}
main(){
    FILE * infile;
    infile=fopen("case1.in","r");
    while(next(infile,tmp_w)) if(strlen(tmp_w)>0) counter(tmp_w);
    for(int i=0; i<lindex&&i<5; i++,t=0){
        for(int j=0; j<lindex; j++)
            if(count[j]>count[t]||(count[j]==count[t]&&strcmp(words[j],words[t])<0)) t=j;
        (strlen(words[t])>0)?printf("%s %d\n",words[t],count[t]):i--;
        count[t]=0;
    }
}
