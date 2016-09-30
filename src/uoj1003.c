#include <stdio.h>
int main(){
	long input;
	scanf("%d",&input);
	int s=1;
	int count=0;
	for (int i=0;i<32;i++){
		if(input & s){
			count++;
		}

		s<<=1;
	}

	printf("%d",count);
	return 0;
}