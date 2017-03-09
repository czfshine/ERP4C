#include <stdio.h>

int main(){

	int data[10];

	for (int i = 0; i < 10; ++i)
	{
		scanf("%d",data+i);
	}

	for( int i=0;i<10;i++)
        for ( int j=0;j<i;j++)
            if(data[i]>data[j]){
                int temp=data[i];
                data[i]=data[j];
                data[j]=temp;
            }

    printf("%d\n%d\n%d\n",data[0],data[1],data[2]);


	return 0;
}