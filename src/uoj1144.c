#include <stdio.h>
 main(){

	long data[100000][2]={{0},{0}};

	long N;
	scanf("%d",&N);
	for(long i=0;i<N;i++)
		scanf("%d %d",&data[i][0],&data[i][1]);
	long M;
	scanf("%d",&M);
	long temp;
	long x,y;
	long level =0;
	for (long i=0;i<M;i++){
		scanf("%d",&temp); 
		x=data[temp-1][0];
		y=data[temp-1][1];
		level=0;
		for(long j=0;j<N;j++){
			if(data[j][0]<=x&& data[j][1]<=y){
				level++;
			}
		}
		printf("%d\n",level-1);
	}
}

