#include "stdio.h" 
#include "math.h" 
#include "string.h" 
#include "stdlib.h" 

#define pass //don't anything

char words[10001][21];
int  count[10001];

//将下一个单词压入word
//@para: infile 输入文件
//@para: word 保存单词的字符串
//@return:!0 sucess
//@return: 0 fail
int next(FILE * infile,char * word){

	return 0;
}

int test(int x ){
	return x+1;
}
int (*test1(void))(int){
	int(* p)(int);
	p=test;
	return p;
}
//打开文件
FILE* open(char * filename){
	int(* p)(int);
	p=test1();
	printf("%d",p(1));
	FILE * in=fopen(filename,"r");
	if(in==NULL)
		pass;
	return in;
}
//计数器
void counter(char * word){

}
//以key排序
void sort(){

}


void print(){

}
main() 
{ 
	char filename[]="case1.in";
	char tmp_w[21];

	FILE * infile;
	infile=open(filename);

	while(next(infile,tmp_w))
		counter(tmp_w);

	sort();
	print();
         
} 

