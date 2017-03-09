#include <stdio.h>
int main(int argc, char const *argv[])
{
	int a,b,s=0;
	while(scanf("%d",&a)>0 && a!=0){
		s=0;
		while(a--){
			scanf("%d",&b);
			s+=b;
		}

		printf("%d\n",s);
	}
	return 0;
}