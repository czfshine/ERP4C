/*

**************************************
10691 ACM 光环
**************************************
Description

话说XCC 经常要打比赛，要知道，ACM界流传着一个经典的定理 ， 那就是rp守恒~因此 XCC 赛前总不忘去膜拜一下

无所不能的Qing教主 ，大赛前大Orz~小赛前小Orz~ 以求可以爆 rp ~~~~然而，要爆rp是要出现 

ac 光环的，传说中的ac 光环是圆的（如下图）；

而损rp 也会出现光环，那就是wa 光环。。。。正方形的（如下图）。





之所以要 rp 守恒是指 ac 光环和 wa 光环要相交，因为两个光环差不多大，

所以此处不考虑它们一方完全包含另一方的情况。如果它们相交了，则 rp 守恒；

否则， ac 光环会因为能量过大导致 rp 溢出。。。。后果嘛，就像int 溢出那样，

rp 迅速负无穷大~~然后 XCC这次比赛就要吃蛋蛋了 T_T ， 当然咯，acm是看实力的，以上就当开个玩笑，这道题很简单，给你一个圆和正方形，判断它们是否能让rp守恒就好了。


**************************************
Input

第一行是六个数字，为wa光环与二维坐标轴平行时的左上顶点，左下顶点和右下顶点。

第二行是三个数字，为ac 光环的圆心和半径。
**************************************
Output

当rp 守恒时，输出 “rp balanced.”，否则 ，输出“Oh no~”。

所有数值都在区间 [-1000,1000] 内
**************************************
Sample Input

5  5  5  3  7  3

1  0  1


**************************************
Sample Output

Oh no~


**************************************
Hint

如果刚好只相交了一个点的话，没让rp守恒哦~


**************************************
Source
**************************************
Author0*/
#include "stdio.h"
int main(int argc, char const *argv[])
{
	int data[6];
	for (int i = 0; i < 6; ++i)
	{
		scanf("%d",&data[i]);
	}

	int x,y,r;

	scanf("%d%d%d",&x,&y,&r);

	int yA,yB,xA,xB;

	yA=data[1];
	yB=data[3];

	xA=data[0];
	xB=data[4];

	int case1,case2,case3,case4,count=0;
	
	case1=4*x*x-4*(x*x-r*r+(yA-y)*(yA-y));
	case2=4*x*x-4*(x*x-r*r+(yB-y)*(yB-y));
	case3=4*y*y-4*(y*y-r*r+(xA-x)*(xA-x));
	case4=4*y*y-4*(y*y-r*r+(xB-x)*(xB-x));

	if(case1>0 ||case2 >0 || case3>0 ||case4>0 ){
		printf("rp balanced.");
	}else{
		if(case1==0) count++;
		if(case2==0) count++;
		if(case3==0) count++;
		if(case4==0) count++;
		if(count>=2){printf("rp balanced.");}else{
		printf("Oh no~");}
	}



	return 0;
}