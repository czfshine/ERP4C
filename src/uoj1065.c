#include <stdio.h>
#define P(x) printf("%d\n",(int )(x));
main (){
	int a[3][4]={{1,3,5,7},{9,11,13,15},{17,19,21,23}};
	int p;
	p=(int)a[1];


	//P(a[2][1])
	printf("%d\n",a[2][1]);
	P(a[1])
	P(a)
	P(a+1)
	P(*a+1)
	P(*(a+1))
	P(a[2]+1)
	P(*(a+1)+1)
	printf("%d\n",*(*(a+2)+2) );

}

#include <stdio.h>

main (){
printf("19\n2016\n2000\n2016\n2004\n2016\n2036\n2020\n21");
}