/*

**************************************
8625 火车上的无奈
**************************************
Description

    由于我校ACM 队的经费并不是很充足，队员们出去比赛不是每个人都那么好运气能坐上飞机。这次

Arctic去哈尔滨比赛，也是坐火车去的。

    火车上的生活是很无聊的，于是很无聊的诞生了一个游戏：给一长条，它2 边可能是不同的接口F和M，

即是有：FM MM FF MF四种长条。已知道F能够接上M，如：FM 和FM合并可以变成FMFM，MM和FF合并

变成MMFF或FFMM。现在给出很多不同的这些长条，它们是否能够连成一个环?


**************************************
Input第一行输入数字T，表示case数，下边T行，描述了此case所有的长条，长条数不会超过20 个。
**************************************
Output如果能组成一个环，输出：LOOP，否则：NO LOOP
**************************************
Sample Input

4

MF MF

FM FF MF MM

MM FF

MF MF MF MF FF


**************************************
Sample Output

LOOP

LOOP

LOOP

NO LOOP


**************************************
Hint
**************************************
Source
**************************************
Author0*/
#include "stdio.h"
int main(int argc, char const *argv[])
{
	int T;
	char ch;
	scanf("%d",&T);
	ch=getchar();
	for (int i = 0; i < T; ++i)
	{
		
		int M=0,F=0;
		ch=' ';
		while(ch!='\n'){
		ch=getchar();
		switch(ch){
			case 'M':M++;break;
			case 'F':F++;break;
		}
		//printf("%c %d %d\n",ch,M,F);
	}	//printf("%d %d",M,F);
		printf("%s\n",M==F?"LOOP":"NO LOOP");
	}
	return 0;
}