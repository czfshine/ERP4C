#include <stdio.h>
#include <math.h> 
int main() {      
	double d, p,r;     
	scanf("%lf%lf%lf",&d,&p,&r);     
	if(d==0){    
		printf("0.0\n"); 
		return 0;
	}

	if(d*(1+r)-p>d||p-d*r<0||p/(p-d*r)<1)         
		printf("God\n");     
	else {          
		printf("%.1f", log10(p/(p-d*r))/log10(1+r));     
	}     
	return 0;
}