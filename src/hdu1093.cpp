#include <stdio.h>
int main(int argc, char const *argv[])
{	
	int n;
	scanf("%d",&n);
	int a,b,s;
	while(n-- ){
		scanf("%d",&a);
		s=0;
		while(a--){
			scanf("%d",&b);
			s+=b;
		}

		printf("%d\n",s);
	}
	return 0;
}