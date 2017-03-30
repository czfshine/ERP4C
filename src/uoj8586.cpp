#include<malloc.h>
#include<stdio.h>
#include <iostream>

using namespace std;
#define OK 0
#define ERROR 1
#define STACK_INIT_SIZE 100 // 存储空间初始分配量
#define STACKINCREMENT 10 // 存储空间分配增量

typedef int SElemType; // 定义栈元素类型
typedef int Status; // Status是函数的类型,其值是函数结果状态代码，如OK等

struct SqStack
{
     SElemType *base; // 在栈构造之前和销毁之后，base的值为NULL
     SElemType *top; // 栈顶指针
     int stacksize;  // 当前已分配的存储空间，以元素为单位

     SqStack()
	{
	// 构造一个空栈S，该栈预定义大小为STACK_INIT_SIZE
	// 请补全代码
		base=(SElemType*) malloc(STACK_INIT_SIZE*(sizeof(SElemType)));
		if(base==NULL)return;
		top=base+1;
		stacksize=STACK_INIT_SIZE;
		//printf("DDD");
		return;
	}

	Status Push(SElemType e)
	{
		// 在栈S中插入元素e为新的栈顶元素
		// 请补全代码
		if(top-base>=stacksize*4){

			base=(SElemType *) realloc(base,(stacksize+STACKINCREMENT)*sizeof(SElemType));

			if(base==NULL){

				return ERROR;
			}
		}else{

			*top=e;
			top++;
		}

		return OK;

	}

	Status Pop(SElemType &e)
	{
		// 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR
		// 请补全代码
		if( top-base<=1){
			return ERROR;
		}

		e=*(--top);

		return OK;
	}

	Status GetTop(SElemType &e)
	{
	// 若栈不空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR
	// 请补全代码
		if( top-base<=1){
			return ERROR;
		}

		e=*(top-1);

		return OK;


	}

	int StackLength()
	{
	// 返回栈S的元素个数
	// 请补全代码

		return top-base-1;

	}

	Status StackTraverse(void fn(SElemType& e))
	{
	// 从栈顶到栈底依次输出栈中的每个元素
		SElemType *p = (SElemType *)malloc(sizeof(SElemType));
		p = top;        //请填空
		if(StackLength() ==0 )printf("The Stack is Empty!"); //请填空
		else
		{
			
			p--;
			while(p-base>=1)            //请填空
			{
				fn(*p);
				p--;               //请填空
			}
		}
		printf("\n");
		return OK;
	}

	int StackEmpty(){

		if(StackLength()>0){
			return 0;
		}else{
			return 1;
		}
	}
}; // 顺序栈

void fun(SElemType &e){

	printf("%d",e);
}

void check()
 { // 对于输入的任意一个字符串，检验括号是否配对
   SqStack s;
   SElemType ch[80],*p,e;
   
    //printf("请输入表达式\n");
     scanf("%s",ch);
     p=ch;
     while(*p) S.StackTraverse(fun);// 没到串尾
       switch(*p)
       {
         case '(':
         case '[':s.Push(*p) ;p++;
                  break; // 左括号入栈，且p++
         case ')':
         case ']':if(!s.StackEmpty()) // 栈不空
                  {
                   s.Pop(e); // 弹出栈顶元素
                    if(*p==')'&&e!='('||*p==']'&&e!='[') {
                      printf("isn't matched pairs\n");
                      exit(ERROR);
                    }
                    else
                    {
                     p++;
                      break; // 跳出switch语句
                    }
                  }
                  else // 栈空
                  {
                    printf("lack of left parenthesis\n");
                    exit(ERROR);
                  }
         default: p++; // 其它字符不处理，指针向后移
       }
     if(s.StackEmpty()) // 字符串结束时栈空
       printf("matching\n");
     else
       printf("lack of right parenthesis\n");
   }

int main()
{
    
	check();
}
