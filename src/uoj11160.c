#include "stdio.h"

#define max(x,y) (x)>(y)?x:y
#define abs(x) x>0?x:-x
int main(int argc, char const *argv[])
{
	char ch;
	int c=0,m=0;

	while(scanf("%c",&ch)>0){
		if(ch=='\n'){
			printf("%d\n",m);
			c=0,m=0;
			continue;
		}
		
		if(ch=='+'){
			c+=1;
		}else{
			c-=1;
		}
		m=max(m,abs(c));
	}
	printf("%d",m);
	return 0;
}