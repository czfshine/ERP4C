#include <stdio.h>
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
	while(1)
	{
		printf("1:Insert element\n2:Delete element\n3:Load all elements\n0:Exit\nPlease choose:\n");
		scanf("%d",&a);
		switch(a)
		{
			case 1: scanf("%d%d",&i,&x);
					
					 v.insert(v.begin()+i,x);
					if(0) printf("Insert Error!\n"); // 判断i值是否合法，请填空
					else printf("The Element %d is Successfully Inserted!\n", x); 
					break;
			case 2: scanf("%d",&i);
			v.erase(v.begin()+i);

					if(0) printf("Delete Error!\n"); // 判断i值是否合法，请填空
					else printf("The Element %d is Successfully Deleted!\n", e);
					break;
			case 3: 
			vector<ElemType>::iterator tempIterator;
			for( tempIterator = v.begin(); tempIterator != v.end(); tempIterator++ )
    				cout << *tempIterator;
    		cout << endl;
					break;
			case 0: return 1;
		}
	}
}