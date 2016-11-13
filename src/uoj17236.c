/*

**************************************
17236 BF
**************************************
Description

不知道看到标题的大家觉得这个是有关什么的题目呢，估计会认为是Boy Friend的缩写之类的吧。嗯，其实我想表达的是Brainfuck‎_(:з」∠)_。

Brainfuck是一种编程语言，虽然它很难看懂，但是它可以完成任何计算操作。

下面说明摘自wiki。

这个语言是基于一个简单的机器模型，除了指令，这个机器还包括：一个以字节为单位、被初始化为零的数组、一个指向该数组的指针（初始时指向数组的第一个字节）、以及用于输入输出的两个字节流。

整个语言只有8条指令：

字符	含义

>	指针加一

<	指针减一

+	指针指向的字节的值加一

-	指针指向的字节的值减一

.	输出指针指向的单元内容（ASCII码）

,	输入内容到指针指向的单元（ASCII码）

[	如果指针指向的单元值为零，向后跳转到对应的]指令的下一指令处

]	如果指针指向的单元值不为零，向前跳转到对应的[指令的下一指令处



如果把这些指令对应c语言的话，就是下面这张表（ptr是char *类型）：

BF	C

>	++ptr;

<	--ptr;

+	++*ptr;

-	--*ptr;

.	putchar(*ptr);

,	*ptr =getchar();

[	while (*ptr) {

]	}

好了，说到这里，估计大家都知道这个题目是干什么的了：给出一个Brainfuck程序以及一串输入，请输出对于这串输入的输出结果.




**************************************
Input

输入包含两部分，第一部分是Brainfuck源程序（在100000个字符内）包括多行(源程序分析过程中忽略空白字符例如：空格' '、制表符'\t'、换行回车'\n')，以#号表示源程序结束，保

证程序没有语法错误。

#号的
**************************************
Output是输入（在100000个字符以内），如果输入为空，则这行是“NULL”，不包含引号。
**************************************
Sample Input

输出这个程序对于对应输入的输出。
**************************************
Sample Output

++++++++++[>+++++++>++++++++++>+++>+<<<<-]>++.>+.+++++++..+++.>++.<<+++++++++++++++.>.+++.------.--------.>+.>.#

NULL
**************************************
Hint

Hello World!
**************************************
Source


**************************************
Author

windows用户请运行这个：

++++++++++++++++[>+++>++++++++++>+++++++++++>++++++++++++>+++++++++++++>++++++++++++++>+++++++++++++++>++++++++++++++++<<<<<<<>>>++.>>>-.

<<<<-----.>>+++.---.+++.---.+++++++.>>++.<--------.----.<-.++++++++.>>+++.>---.<<>>+++

++.<+.<<<>+++++.>++++.>>------------.<<>>>-----.<<---.----.>>++++++.<<>-----

-.>>++++.<<<<>>>.<<0*/
//coding:utf-8
#include <stdio.h>
#include <stdlib.h>

//The chars
#define ADD '+' /* 字节加一*/
#define SUB '-' /* 字节减一*/
#define NXT '>' /* 指针左移*/
#define PRV '<' /* 指针右移*/
#define INN ',' /* 输入数字*/
#define OUT '.' /* 输出数字*/
#define IFS '[' /* 判断开始*/
#define IFE ']' /* 判断结束*/
//string 
#define s_infile_error "[error]:打开文件%s失败\n"
#define s_ife_error "[error]:在代码的%d处没有与之对应的']'\n"
bool hasprint=false;

//--------------stack start  ----------------
//用来存放'['字符位置的堆栈
struct stacknode {
	int cur;
	struct stacknode  * next;
};

struct stacknode* TheStack ;

int is_empty(){
	return TheStack==NULL;
}

void push ( int cur ){

	struct stacknode* testnew;
	testnew = (struct stacknode *) malloc (sizeof(struct stacknode ));
	if (testnew == NULL ){
	}else {

		testnew-> cur=cur;
		testnew -> next=TheStack;
		TheStack=testnew;

	}
}

int pop (void ){

	struct stacknode * f;
	int cur;

	if (!is_empty()){
		f=TheStack;
		cur=f->cur;
		TheStack=f->next;
		free(f);
		return cur;

	}

	return -1;
}

void printstack(){
	if(hasprint){
		struct stacknode * p;
		p=TheStack;
		printf("The Stack ");

		if (p==NULL){ printf("Is empty\n");}

		while (p!= NULL){
			printf("%d,",p->cur);
			p=p->next;
		}
		printf("\n");
	}
}
//-----------end the stack --------------------

//----------debug------------------
void printbuff(int bfs,int cur,char * sheet){
	if(hasprint){
		for (int i=0;i<bfs;i++){
			if (i!= cur){
				printf("[%03d]\t",sheet[i]);
			}else{
				printf(">%03d<\t",sheet[i]);
			}
			
			if (!((i+1)%10)){
				printf("\n");
			}
		}
	}

}
void printinfo(FILE * inf,char ch){
	if (hasprint){
		printf("------%d---%c-----\n",(int) ftell(inf),ch);
	}

}
//-------------------------
int toIFE(char * f){
	char ch;
	while ((ch=(char)fgetc(f))){
		if(ch==IFE){
			//fseek(f,-1L,SEEK_CUR);
			return 0 ;
		}
	}
	return 1;
}
void help(){
	printf("usage:\n\tbf -[option] <filename>\n");
	printf("The option :\n\t-p\tprint full info\n");
	printf("\t-n size\tthe sheet size(default 30)\n");//TODO
}
char * create_sheet(int * size){
	char * sheet;
	sheet = (char *) malloc (* size);
}
int main (int argc,char **argv){

	int buffsize= 30;
	//open file 
	char inf[100000]={0};
	int  incur=0;
	//input
	char s='a'; 
	while(s!='#'){
		s=getchar();
		inf[incur]=s;
		incur++;
	}

	char input[100000]={0};
	int inputcur=0;
	s=getchar();
	s='a';
	while(s!='\n'){
		s=getchar();
		input[inputcur]=s;
		inputcur++;
	}
	if(input[0]=='N'&&input[1]=='U'&&input[2]=='L'&& input[3]=='L'){
		input[0]=input[1]=input[2]=input[3]=0;
	}



	//the paper sheet
	char * sheet;
	int cur=0;
	sheet=create_sheet(&buffsize);


	
	char ch;
	while (ch=inf[incur]){
		switch (ch){
			case ADD: sheet[cur]+=1 ;break;
			case SUB: sheet[cur]-=1 ;break;
			case NXT: cur =(cur+1)%buffsize ;break;
			case PRV: cur =(cur-1+buffsize)%buffsize;break;
			case INN: sheet[cur]=input[inputcur];inputcur++;break;
			case OUT: printf("%c",sheet[cur]); break;
			case IFS: {
				push(incur);

				if (sheet[cur]){
					
				}else{
					pop();
					toIFE(inf);
				}

				break;
			}
			case IFE:{

				long cut_f=(long)pop()-1;
				if(cut_f>=0){

					//printf("THE IFE %d\n",cut_f);
					incur=cut_f;

				}else{


				}

				break;

			}
		}
	}
	return 0;
}