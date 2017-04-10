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
	list<note> Lu;


	//链表操作
	//一个链表
	list<int> l;
	//在链表头部插入元素
	l.push_front(1);
	//尾部
	l.push_back(2);


	
	//返回第一个元素的引用
	int n= l.front()    // = 1
    //返回最后一元素的引用
	n = l.back()     // = 2
	//返回第一个元素的迭代器(iterator)
	list<int>::iterator it = l.begin();    // *it = 1
    //返回最后一个元素的下一位置的指针(list为空时end()=begin())
    it = l.end();    

	return 0;
}