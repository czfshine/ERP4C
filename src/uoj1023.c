#include "stdio.h"

int main(int argc, char const *argv[])
{
	float a,b,c;
	char op;

	scanf("%f%c%f",&a,&op,&b);
	switch(op)
	{
		case '+':c=a+b;break;
		case '-':c=a-b;break;
		case '*':c=a*b;break;
		case '/':c=a/b;break;
		default: printf("error");
		return 0;
	}
	printf("result=%.2f",c);
	return 0;
}