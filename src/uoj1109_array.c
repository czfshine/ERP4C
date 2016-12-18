#include "stdio.h" 
#include "math.h" 
#include "string.h" 
#include "stdlib.h" 

#include "ctype.h"

#define pass //I can't do anything. This world is mad!

char words[10001][21]={0}; //keys
int  count[10001]={0};     //values

int lindex=0;
//将下一个单词压入word
//@para: infile 输入文件
//@para: word 保存单词的字符串
//@return:!0 sucess
//@return: 0 fail
int next(FILE * infile,char * word){
	char ch,i=0;

	
	while((ch=getc(infile))!=EOF){
		if(ch=='-'){
			if((ch=getc(infile))=='\n'){
				continue;
			}else{
				fseek(infile,-1L,SEEK_CUR);
				break;
			}
		}

		if(isalpha(ch)){
			word[i++]=tolower(ch);
			if (i>20) 
				pass;
		}else{
			word[i]='\0';
			return 1;
		}

	}
	if(i>0){
		word[i]='\0';
		return 1;
	}
	return 0;
}
//打开文件
FILE* open(char * filename){
	FILE * in=fopen(filename,"r");
	if(in==NULL)
		pass;
	return in;
}
int canfind(char * word ){
	int i=0;
	while(words[i][0]!='\0' &&(strcmp(words[i++],word)!=0 )){
		printf("%s,%s,%d",words[i],word,i);
	}
	if(words[i][0]=='\0'){
		return 0;
	}else{
		return i-1;
	}
}
//计数器
void counter(char * word){
	//printf("%s\n",word);
	int index=0;

	printf("%s,%d\n",word,canfind(word));
	if(index=canfind(word)){
		count[index]++;
	}else{
		count[lindex]=1;
		strcpy(words[lindex++],word);
	}
}
//以key排序
void ksort(){

}


void print(){
	for (int i = 0; i < lindex; ++i)
	{
		printf("%04d-%s\n",count[i],words[i]);
	}
}
main() 
{ 
	char filename[]="case1.in";
	char tmp_w[21];

	FILE * infile;
	infile=open(filename);

	while(next(infile,tmp_w))
		counter(tmp_w);

	ksort();
	print();
} 

