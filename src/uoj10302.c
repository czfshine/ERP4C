#include "stdio.h"
#include "math.h"

int data[10000][10000];

long f(int n,int k){

	if(k==0) return 1;

	if(k>=floor(log(n))) return f(n,floor(log(n)));
	int long sum=0;
	if(k>0) {
		for (int i = 0; i <=k; ++i)
		{
			sum+=f(n-pow(2,i), i);
		}
		return sum;
	}
}

int main(int argc, char const *argv[])
{
	printf("%ld",f(5,0));
	return 0;
}