#include <stdio.h>
#include <iterator>
#include <iostream>
#include <vector>
#define OK 1 
#define ERROR 0
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
#define ElemType int

using namespace std;
int main()
{
	std::vector<ElemType> v;
	int a, i;
	ElemType e, x;
	if(v.empty())    // 判断顺序表是否创建成功
	{
		printf("A Sequence List Has Created.\n");
	}
	vector<ElemType>::iterator tempIterator;
	while(1)
	{
		printf("1:Insert element\n2:Delete element\n3:Load all elements\n0:Exit\nPlease choose:\n");
		scanf("%d",&a);
		switch(a)
		{
			case 1: scanf("%d%d",&i,&x);

					if(i<1||i-1>v.size()){
						printf("Insert Error!\n");}
					else{

						v.insert(v.begin()+i-1,x);
						printf("The Element %d is Successfully Inserted!\n", x); 
					}

					break;
			case 2: scanf("%d",&i);
					if(i<1 ||i>=v.size()){
						printf("Delete Error!\n");
					}else{
						e=v.at(i-1);
						v.erase(v.begin()+i-1);
						printf("The Element %d is Successfully Deleted!\n", e);
					}
					break;
			case 3: 
				
					if(v.size()==0) 
						printf("The List is empty!");  // 请填空
					else
					{
						printf("The List is: ");
						for( tempIterator = v.begin(); tempIterator != v.end(); tempIterator++ )
    						cout << *tempIterator <<" ";
					}

					printf("\n");

					break;
			case 0: return 1;
		}
	}
}
