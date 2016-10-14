// like uoj1018 :)

#include "stdio.h"
main(){
	int data[3];
    int i,j,temp;
	scanf("%d%d%d",&data[0],&data[1],&data[2]);
	for( i=0;i<3;i++){
        for ( j=0;j<i;j++){
            if(data[i]>data[j]){
                temp=data[i];
                data[i]=data[j];
                data[j]=temp;
            }
        }

    }

    printf("%d",data[0]);
}

