//stl list
//载入头文件
#include <iostream>
#include <list>

using namespace std;


typedef struct {
	char name[21];
	int id;
}  note ;


int main(int argc, char const *argv[])
{
	//建立
	list<int> L0;       // 空链表
	list<int> L1(9);   // 建一个含一个元素的链表
	list<int> L2(5,1); // 建一个多个个元素的链表
	list<int> L3(L2);  // 复制L2的元素，重新建立一个链表
	list<int> L4(L0.begin(), L0.end());//建一个含L0一个区域的链表

	//其他元素类型的链表

	list<double> Ld;
	list<int [3]>Larray;
	list<note> Lu;


	//链表操作
	list<int> l;
	l.push_front(1);
	l.push(2);


	return 0;
}