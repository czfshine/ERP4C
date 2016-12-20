#include "stdio.h" 
#include "math.h" 
#include "string.h" 
#include "stdlib.h" 

#include<ctype.h>
#include<malloc.h>
#define LEN sizeof(struct c_word)
int num=0;//统计不同单词个数
struct c_word //用结构体变量存储读入的单词
{
	char word[30];//存储读入单词
	int count;//统计相同单词个数
	struct c_word *next;
};
/*定义函数插入新单词*/
struct c_word *insert(struct c_word *head,struct c_word *new_word)
{
	struct c_word *p0=new_word,*p1=head,*p2;
	int n;
         if(strlen(new_word->word)<1) return head;
	if(head==NULL) //考虑到第一次添加新单词的情况
	{
		head=p0;p0->next=NULL;
		p0->count=1;num++; //单词数为1
	}
	else
	{ 
		while((n=strcmp(p0->word,p1->word))>0&&p1->next!=NULL) 
			/*按字典顺序插入*/
		{
			p2=p1;
			p1=p1->next;
		}
		if(n==0)
			++p1->count; //读入的单词已出现过
		else   //在适当的位置添加新单词
			if(n<0)
			{
				if(head==p1) head=p0;/*插到原来第一个节点之前*/
				else p2->next=p0;/*插到p2指向节点后*/
				p0->next=p1;
				p0->count=1;
				num++; //不同单词数加1
			}
			else //插到最后的节点后
			{ 
				p1->next=p0;
				p0->next=NULL;
				p0->count=1;
				num++; //不同单词数加1
			}
	}
	return head;
}
void print(struct c_word *head)
{
	int i,max;
	struct c_word *p1,*p2;
	if(num<5) //不足5个单词时，按序输出全部单词
		while(head!=NULL)
		{
			printf("%s %d\n",head->word,head->count);
			head=head->next;
		}
	else
		for(i=0;i<5;i++) //输出出现次数最多的前5个单词及其出现次数
		{
			p1=head;
			p2=head;
			max=p1->count;
			while(p1->next!=NULL)
			{
				if(p1->count>max) 
				{
					max=p1->count;
					p2=p1;
				}
				p1=p1->next;
			}
			printf("%s %d\n",p2->word,p2->count);
			p2->count=0; //将已输出的单词出现次数清0，以免重复计算
		}
}

main() {

FILE *fp;
	int i=0;
	char ch;
	struct c_word *new_word=(struct c_word *)malloc(LEN); //为读入单词创建新节点
	struct c_word *head=NULL;
	if((fp=fopen("case1.in","r"))==NULL) //打开文件，若失败则输出信息后退出程序
	{
		printf("cannot open file\n");
		return 0;
	}
	ch=fgetc(fp);
	while(!islower(ch)&&!isupper(ch)) /*去掉第一个单词前的标点*/
		ch=fgetc(fp);
	while(ch!=EOF) //读入字符，遇到EOF后结束
	{
		if(ch=='-') //判断当前字符是否行末连字符
		{
			ch=fgetc(fp);
			if(ch=='\n') //遇到行末连字符，继续读入字符
			{
				ch=fgetc(fp);
				continue;
			}
			new_word->word[i]='\0';i=0;
			head=insert(head,new_word);
			new_word=(struct c_word *)malloc(LEN);
		}
		if(ispunct(ch)||isspace(ch)||isdigit(ch)) //判断当前字符是否标点，空格，数字
		{
			ch=fgetc(fp);//读入下一字符
			if(ispunct(ch)||isspace(ch)||isdigit(ch)) //是就跳到下次循环
				continue;
			new_word->word[i]='\0';i=0;   //单词末加空操作符并把i清0
			head=insert(head,new_word); //插入新单词
			new_word=(struct c_word *)malloc(LEN);
		}
		else
		{
			new_word->word[i++]=tolower(ch); //添加新字母
			ch=fgetc(fp);
			if(ch==EOF)
			{
               new_word->word[i]='\0';i=0;   
			   head=insert(head,new_word);
			}
		}
	}
	print(head); //输出结果
	fclose(fp); //关闭文件

	}
