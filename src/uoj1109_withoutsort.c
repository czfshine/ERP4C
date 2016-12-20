#include "stdio.h" 
#include "math.h" 
#include "string.h" 
#include "stdlib.h" 
#include "ctype.h"
char words[10001][21]={0}; //keys
int  count[10001]={0}, lindex=0;     //values
int next(FILE * infile,char * word){
	char ch,i=0;
	while((ch=getc(infile))!=EOF){
		if(isalpha(ch)){
			word[i++]=tolower(ch);
		}else if(ch=='-')
			if((ch=getc(infile))=='\n')
				continue;
			else{
				fseek(infile,-1L,SEEK_CUR);
				word[i]='\0';
				return 1;
				break;
			}

		else {
			word[i]='\0';
			return 1;
		}
		
	}
	if(i){
		printf("d");
		word[i]='\0';
		return 1;
	}
	return 0;
}
FILE* open(char * filename){
	FILE * in=fopen(filename,"r");
	return in;
}
int canfind(char * word ){
	int i=0;
	if(lindex>2&&strcmp(words[lindex-1],word)==0)
		return lindex-1;
	while(words[i][0]!='\0' &&(strcmp(words[i++],word)!=0 )){}
	if(words[i][0]=='\0'){
		return -1;
	}else{
		return i-1;
	}
}
void counter(char * word){
	int index=0;
	if((index=canfind(word))!=-1){
		count[index]++;
	}else{
		count[lindex]=1;
		strcpy(words[lindex++],word);
	}
}
void output(){
	for(int i=0; i<lindex&&i<5; i++) //输出已有单词中前5个最多的单词
    {
        int t=0;
        for(int j=0; j<lindex; j++)
        {
            if(count[j]>count[t]) t=j;
            else if(count[j]==count[t])
            {
                if(strcmp(words[j],words[t])<0) t=j;
            }
        }
        if(strlen(words[t])>0){
        printf("%s %d\n",words[t],count[t]);
        count[t]=0;}
        else{
          count[t]=0;
          i--;
        }
    }
}
main() 
{ 
	char filename[]="case1.in";
	char tmp_w[21];
	FILE * infile;
	infile=open(filename);
	while(next(infile,tmp_w))
		if(strlen(tmp_w)>0)
			counter(tmp_w);
	output();
	
} 