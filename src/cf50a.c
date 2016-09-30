#include <stdio.h>
int main(){
	int N,M;
	scanf("%d%d",&N,&M);
	if(N%2==0 || M%2==0){
		printf("%d",N*M/2);
	}else{
		printf("%d",(N*M-1)/2);
	}
	return 0;
}