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
		//printf("%c",ch);

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

//printf("%s\n",word);
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
		//printf("%s,%s,%d\n",words[i],word,i);
	}

	//printf("%s,%s,%d\n",words[i-1],word,i);
	if(words[i][0]=='\0'){
		return 0;
	}else{
		if (i==1)
		{
			return -1;
		}
		return i-1;
	}
}
//计数器
void counter(char * word){
	//printf("%s\n",word);
	int index=0;

	//printf("%s,%d\n",word,canfind(word));
	if(index=canfind(word)){
		if(index==-1){
			count[0]++;
			return ;
		}
		count[index]++;
	}else{
		count[lindex]=1;
		strcpy(words[lindex++],word);
	}
}

int len(){
	int i=0;
	while(words[i++][0]!='\0'){}
		return i-1;
}

void swap(char *w1,char *w2){
	char ts[21];
	char * t=ts;
	strcpy(t,w1);
	strcpy(w1,w2);
	strcpy(w2,t);
}

void vsort(){

	int l=len();

	for (int i = 0; i < l; ++i)
	{
		for (int j = i+1; j < l; ++j)
		{
			if(count[i]<count[j]){
				
				swap(words[i],words[j]);

				int t;
				t=count[i];
				count[i]=count[j];
				count[j]=t;
			
			}
		}
	}

}
//以key在区间排序
void ksort(int s,int e){
	int l=len();

	for (int i = s; i < e+1; ++i)
	{
		for (int j = i+1; j < e+1; ++j)
		{
			if(strcmp(words[i],words[j])>0){

				swap(words[i],words[j]);

				int t;
				t=count[i];
				count[i]=count[j];
				count[j]=t;
			}
		}
	}
}

void sortk_v(){

	vsort();
	 //print();
	int num=count[0];
	int cur=0;
	int l=len();
	while (cur<l-1){
		int s_cur=cur;
		while(count[cur++]==num&&cur<l-1){}
		if(num!=1){

			ksort(s_cur,cur-2);
			//printf("%d,%d",s_cur,cur-2);
		}else{
			ksort(s_cur-1,l-1);
			//printf("%d,%d",s_cur-1,l-1);
		}
		num=count[cur-1];
		//printf("%d",num);
		//printf("%d\n",cur);
    }
}

void print(){
	for (int i = 0; i < lindex; ++i)
	{
		printf("%04d-%s\n",count[i],words[i]);
	}
}

void output(){

	for (int i = 0; i < 5; ++i)
	{
		printf("%s %d\n",words[i],count[i]);
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
	sortk_v();
    print();
	//printf("%d",len());
	output();
} 

