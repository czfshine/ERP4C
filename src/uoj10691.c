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