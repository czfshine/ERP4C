#include "stdio.h" 
#include "math.h" 
#include "string.h" 
#include "stdlib.h" 

#include "ctype.h"

#define pass //I can't do anything. This world is mad!

#define OUTPUTMAX 5
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
		if(isalpha(ch)){
			word[i++]=tolower(ch);
			if (i>20) 
				pass;
		}else{
			if(ch!='-'){
			word[i]='\0';
			return 1;}
		}

		if(ch=='-'){
			if((ch=getc(infile))=='\n'){
				continue;
			}else{
				fseek(infile,-1L,SEEK_CUR);
				word[i]='\0';
				return 1;
				break;
			}
			
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

//寻找word的位置
//@para: word  单词
//@return: >=0 单词的索引
//@return: -1  单词不在列表里
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


//计数器
//@para: word  待计数的单词
void counter(char * word){
	int index=0;

	if(index=canfind(word)!=-1){
		count[index]++;
	}else{
		count[lindex]=1;
		strcpy(words[lindex++],word);
	}

}

void swap(char *w1,char *w2){
	char ts[21];
	char * t=ts;
	strcpy(t,w1);
	strcpy(w1,w2);
	strcpy(w2,t);
}

void vsort(){

	int l=lindex,t;

	for (int i = 0; i < l; ++i)
	{
		for (int j = i+1; j < l; ++j)
		{
			if(count[i]<count[j]){
				
				swap(words[i],words[j]);
				t=count[i];
				count[i]=count[j];
				count[j]=t;
			
			}
		}
	}

}

//以key在区间排序
void ksort(int s,int e){
	int l=lindex,t;
	if(s<0) s=0;
	for (int i = s; i < e+1; ++i)
	{
		for (int j = i+1; j < e+1; ++j)
		{
			if(strcmp(words[i],words[j])>0){

				swap(words[i],words[j]);

				t=count[i];
				count[i]=count[j];
				count[j]=t;
			}
		}
	}
}

void sortk_v(){

	vsort();

	int num=count[0];
	int cur=0;
	int l=lindex;
	while (cur<l-1){
		int s_cur=cur;
		while(count[cur++]==num&&cur<l-1){}
		if(num!=1)
			ksort(s_cur-1,cur-2);
		else
			ksort(s_cur-1,l-1);

		num=count[cur-1];
    }

}

void print(){
	for (int i = 0; i < lindex; ++i)
	{
		printf("%04d-%s",count[i],words[i]);
		for (int j = 0; j < strlen(words[i]); ++j)
			printf(" %d",words[i][j]);
		printf("\n");
	}
	printf("---------------------\n");

}

void output(){

	for (int i = 0; i < OUTPUTMAX; ++i)
		printf("%s %d\n",words[i],count[i]);
	
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

	sortk_v();
	output();
} 

