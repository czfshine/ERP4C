/*

**************************************
1109 综合实验：文件操作与字符处理
**************************************
Description

在当前目录中存在文件名为"case1.in"（其中case后为数字1，不是字母l，写错提交后会判错）的文本文件，

其内容为一篇英文文章（以EOF作为结束标志）。现要求读取该文本文件内容，统计文章中每个单词出现的次数，

并输出出现次数最多的前5个单词及其出现次数（按出现次数由多到少的顺序输出，次数相同时按字典顺序输出，

不足5个单词时，按序输出全部单词）。程序中注意如下细节：

（1）	空格、标点符号与回车符起到分隔单词的作用。

（2）	文章一行的末尾可能有连字符，出现连字符时，该行最末的字符串与下行最先出现的字符串构一个单词；

（3）	名词缩写算一个单词；

（4）	数字不算单词；

（5）	单词不区分大小写；

（6）	输出时单词全使用小写；
**************************************
Input

文件case1.in中一篇英文文章，包含多段文字，单词数不超过10000，每个单词不超过20个字符
**************************************
Output

按题意输出答案
**************************************
Sample Input

（如case1.in内容如下） 

I am a student. My school is SCAU. It is a beau-

tiful university. I like it.


**************************************
Sample Output

a 2

i 2

is 2

it 2

am 1


**************************************
Author0*/
#include "stdio.h"
//todo
struct node{
	int count;
	struct node *child[26];
};
struct max{
	char word[21];
	int count;
	struct max* next;
};


void getword(FILE *fp,char * str){

}

void addnode(struct node * root,char * word ){


}

void find5max(struct node * root,char * * data){

}
void q(char * * data){

}
int main(int argc, char const *argv[])
{
	char word[21]="";
	return 0;
}