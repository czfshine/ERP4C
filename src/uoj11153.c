/*

**************************************
11153 kill boss
**************************************
Description

      Acmer最近喜欢上了玩某个游戏，这个游戏的格斗风格是以格挡，招架，攻击为主，acmer最近打一个boss打了几遍，还是没有打赢，但是经过几次失败后，

acmer大概摸清了boss的出招规律，所以她做好了相应的出招式，acmer被boss砍掉n滴血后会挂掉，对应的只要acmer在挂掉前砍掉boss m滴血，acmer就能赢了。

现在给你boss的最终出招表和acmer的出招表，问你谁能赢，如果都不能赢那就输出impossible。需要注意的是这个游戏中可以以攻为守，给定系数k，我们用正数表示攻击系数，

负数表示防守系数

，如果双方都是攻击，攻击系数大的可以突破别人的攻击（即对方攻击无效），并且给对手所对应k点的伤害，相等的时候就互不伤害。

当双方一个攻击，一个防守时，攻击系数大于防守系数时，可以突破防守（即对方防守无效），并且给对手所对应k点的伤害。

当防守系数不小于攻击系数能够防守住攻击。 如果双方都是防守，那就什么都没有发生。



（出题人xym）


**************************************
Input

第一行有三个数n(1<=n<=1000)，m(1<=m<=1000),d(1<=d<=10000)，n表示acmer血量，m表示boss血量，d表示出招的数目。

接下来有两行，第一行表示boss的招式表，所有数绝对值都不大于10000

第二行表示 acmer的招式表。所有数绝对值都不大于10000
**************************************
Output

输出一行表示谁赢，acmer表示acmer赢，boss表示boss赢，impossible表示不知道谁赢。
**************************************
Sample Input

10 10 10

1 2 3 -5 3 -6 7 10 15 20

-1 -3 -2 5 5 -5 11 1 2 3


**************************************
Sample Output

acmer
**************************************
Author0*/
#include "stdio.h"

int main(int argc, char const *argv[])
{
	int m,n,d;
	scanf("%d %d %d",&m,&n,&d);
	int a[d],b[d];
	for (int i = 0; i < d; ++i)
	{
		scanf("%d",a+i);
	}
	for (int i = 0; i < d; ++i)
	{
		scanf("%d",b+i);
	}

	for (int i = 0; i < d; ++i)
	{	
		if(n<=0 || m<=0)
			break;
		if(a[i]>0&&b[i]>0){
			if(a[i]>b[i]){
				m-=a[i];
			}else{
				if(a[i]<b[i])
					n-=b[i];
			}
			continue;
		}

		if(a[i]>0&&b[i]<0){
			if(a[i]+b[i]>0)
				m-=a[i];
			continue;
		}
		if(a[i]<0 &&b[i]>0){
			if(a[i]+b[i]>0)
				n-=b[i];
			continue;
		}

	}
	if(m<=0){
		printf("boss");
	}else{
		if(n<=0){
		printf("acmer");
	}else{
		printf("impossible");
	}
	}
	//printf("%d,%d",n,m);
	return 0;
}