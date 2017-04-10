//stl list
//载入头文件
#include <iostream>
#include <list>

using namespace std;


typedef struct {
	char name[21];
	int id;
}  note ;

bool myFun(const int& value) { return (value < 2); }
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
	l.push_back(3);

	l.pop_back()//删除链表尾的一个元素
	l.pop_front()//删除链表头的一元素
	l.clear()//删除所有元素

	l.push_back(3);
	l.push_back(3);
	l.push_back(4);

	l.remove(4);//删除链表中匹配值的元素(匹配元素全部删除)

	//remove_if()删除条件满足的元素(遍历一次链表)，参数为自定义的回调函数
	// 小于2的值删除

	l.push_back(1);

	l.remove_if(myFun);    // list1(3)　


	//empty()判断是否链表为空

	//大小
	list<int>::size_type nRet = l.size();      

	//返回第一个元素的引用
	int n= l.front()   ; 
    //返回最后一元素的引用
	n = l.back() ;   
	//返回第一个元素的迭代器(iterator)
	list<int>::iterator it = l.begin();    
    //返回最后一个元素的下一位置的指针(list为空时end()=begin())
    it = l.end();

    l.erase(it-1);//删除一个元素或一个区域的元素    
	return 0;
}