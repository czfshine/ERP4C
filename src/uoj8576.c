/*

**************************************
8576 顺序线性表的基本操作
**************************************
Description

#include<stdio.h>

#include<malloc.h>

#define OK 1 

#define ERROR 0

#define LIST_INIT_SIZE 100

#define LISTINCREMENT 10

#define ElemType int



typedef struct

{

	int *elem;

	int length;

	int listsize;

}SqList;



int InitList_Sq(SqList &L)

{

// 算法2.3，构造一个空的线性表L，该线性表预定义大小为LIST_INIT_SIZE

// 请补全代码



}



int Load_Sq(SqList &L)

{

// 输出顺序表中的所有元素

	int i;

	if(_________________________) printf("The List is empty!");  // 请填空

	else

	{

		printf("The List is: ");

		for(_________________________) printf("%d ",_________________________);  // 请填空

	}

	printf("\n");

	return OK;

}



int ListInsert_Sq(SqList &L,int i,int e)

{

// 算法2.4，在顺序线性表L中第i个位置之前插入新的元素e

// i的合法值为1≤i≤L.length +1

// 请补全代码



}



int ListDelete_Sq(SqList &L,int i, int &e)

{

// 算法2.5,在顺序线性表L中删除第i个位置的元素，并用e返回其值

// i的合法值为1≤i≤L.length

// 请补全代码



}



int main()

{

	SqList T;

	int a, i;

	ElemType e, x;

	if(_________________________)    // 判断顺序表是否创建成功

	{

		printf("A Sequence List Has Created.\n");

	}

	while(1)

	{

		printf("1:Insert element\n2:Delete element\n3:Load all elements\n0:Exit\nPlease choose:\n");

		scanf("%d",&a);

		switch(a)

		{

			case 1: scanf("%d%d",&i,&x);

					if(_________________________) printf("Insert Error!\n"); // 判断i值是否合法，请填空

					else printf("The Element %d is Successfully Inserted!\n", x); 

					break;

			case 2: scanf("%d",&i);

					if(_________________________) printf("Delete Error!\n"); // 判断i值是否合法，请填空

					else printf("The Element %d is Successfully Deleted!\n", e);

					break;

			case 3: Load_Sq(T);

					break;

			case 0: return 1;

		}

	}

}


**************************************
Input

测试样例格式说明：

根据菜单操作：

1、输入1，表示要实现插入操作，紧跟着要输入插入的位置和元素，用空格分开

2、输入2，表示要实现删除操作，紧跟着要输入删除的位置

3、输入3，表示要输出顺序表的所有元素

4、输入0，表示程序结束


**************************************
Sample Input
1

1 2

1

1 3

2

1

3

0
**************************************
Sample Output
A Sequence List Has Created.

1:Insert element

2:Delete element

3:Load all elements

0:Exit

Please choose:

The Element 2 is Successfully Inserted!

1:Insert element

2:Delete element

3:Load all elements

0:Exit

Please choose:

The Element 3 is Successfully Inserted!

1:Insert element

2:Delete element

3:Load all elements

0:Exit

Please choose:

The Element 3 is Successfully Deleted!

1:Insert element

2:Delete element

3:Load all elements

0:Exit

Please choose:

The List is: 2 

1:Insert element

2:Delete element

3:Load all elements

0:Exit

Please choose:
**************************************
Author0*/
#include<stdio.h>
#include<malloc.h>
#define OK 1 
#define ERROR 0
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
#define ElemType int
//todo
typedef struct
{
	int *elem;
	int length;
	int listsize;
}SqList;

int InitList_Sq(SqList &L)
{
// 算法2.3，构造一个空的线性表L，该线性表预定义大小为LIST_INIT_SIZE
// 请补全代码

	L.elem=(int *)malloc(4*LIST_INIT_SIZE);
	L.length=0;
	L.listsize=100;
	return OK;


}

int Load_Sq(SqList &L)
{
// 输出顺序表中的所有元素
	int i;
	if(L.length==0) printf("The List is empty!");  // 请填空
	else
	{
		printf("The List is: ");
		for(i=0;i<L.length;i++) printf("%d ",*(L.elem+i));  // 请填空
	}
	printf("\n");
	return OK;
}

int ListInsert_Sq(SqList &L,int i,int e)
{
// 算法2.4，在顺序线性表L中第i个位置之前插入新的元素e
// i的合法值为1≤i≤L.length +1
// 请补全代码
	int * p,* p1;
	if(++L.length>L.listsize) {
		L.elem=(int *)realloc(L.elem,(L.listsize+LISTINCREMENT)*4);
		L.listsize+=LISTINCREMENT;
	}

	p=L.elem+i-1;

	for(p1=L.elem+L.length-1;p1>=p;p--){
		*(p+1)=*p;
	}
	*p=e;
	return OK;
}

int ListDelete_Sq(SqList &L,int i, int &e)
{
// 算法2.5,在顺序线性表L中删除第i个位置的元素，并用e返回其值
// i的合法值为1≤i≤L.length
// 请补全代码
	int * p,* p1;
	L.length--;

	p=L.elem+i-1;
	e=*p;

	for(p++;p<=L.elem+L.length-1;++p){
		*(p-1)=*p;
	}
	return OK;

}

int main()
{
	SqList T;
	int a, i;
	ElemType e, x;
	if(InitList_Sq(T))    // 判断顺序表是否创建成功
	{
		printf("A Sequence List Has Created.\n");
	}
	while(1)
	{
		printf("1:Insert element\n2:Delete element\n3:Load all elements\n0:Exit\nPlease choose:\n");
		scanf("%d",&a);
		switch(a)
		{
			case 1: scanf("%d%d",&i,&x);
					if(ListInsert_Sq(T,i,x)) printf("Insert Error!\n"); // 判断i值是否合法，请填空
					else printf("The Element %d is Successfully Inserted!\n", x); 
					break;
			case 2: scanf("%d",&i);
					if(e=ListDelete_Sq(T,i,e)) printf("Delete Error!\n"); // 判断i值是否合法，请填空
					else printf("The Element %d is Successfully Deleted!\n", e);
					break;
			case 3: Load_Sq(T);
					break;
			case 0: return 1;
		}
	}
}