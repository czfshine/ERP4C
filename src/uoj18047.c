#include "stdio.h"
int main(int argc, char const *argv[])
{
	int num[3]={0};
	//printf("153\n370\n371\n407") 23333333333333333
	for (num[0]=0;num[0]<=9;num[0]++){
		for (num[1]=0;num[1]<=9;num[1]++){
			for (num[2]=0;num[2]<=9;num[2]++){
				if(num[0]*num[0]*num[0]+num[1]*num[1]*num[1]+num[2]*num[2]*num[2]==num[0]*100+num[1]*10+num[2] && num[0]*100+num[1]*10+num[2] >=100){
					printf("%d%d%d\n",num[0],num[1],num[2]);
				}
			}
		}
	}
	return 0;
}