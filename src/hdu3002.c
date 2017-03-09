#include <stdio.h>
int main(int argc, char const *argv[])
{	
	int n;
	scanf("%d",&n);
	int a,b;
	while(n-- && (scanf("%d%d",&a,&b))){
		printf("%d\n",a+b);
	}
	return 0;
}