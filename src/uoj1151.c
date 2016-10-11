#include <stdio.h>
int F(int x){

	if(x<3){
		return x;
	}else{
		if (x%3==0){
			return F(x/3)*2;
		}

		if(x%3==1){
			return F((x-1)/3)+1;
		}

		if(x%3==2){
			return F((x-2)/3)+2;
		}
	}
}
int main(int argc, char const *argv[])
{
	int a;
	scanf("%d",&a);

	printf("%d",F(a));
	return 0;
}