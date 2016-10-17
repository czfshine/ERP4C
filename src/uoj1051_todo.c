#include <stdio.h>
//TODO
void findmax(int * row,int * re){
	int cmax,c;
	cmax=row[0];
	for (int i = 1; i < 4; ++i)
	{
		if(cmax<row[i]){
			cmax=row[i];
			re[0]=0;
			re[1]=0;
			re[2]=0;
			re[3]=0;
			re[i]=1;
		}else{if(cmax==row[i])
			re[i]=1;
		}
	}

}

void findmin(int * row,int * re){
	int cmin,c;
	cmin=row[0];
	for (int i = 1; i < 4; ++i)
	{
		if(cmin>row[i]){
			cmin=row[i];
			re[0]=0;
			re[1]=0;
			re[2]=0;
			re[3]=0;
			re[i]=1;
		}else{if(cmin==row[i])
			re[i]=1;
		}
	}
}

int main(int argc, char const *argv[])
{
	int data[3][4]={0};
	char ismax[3][4]={0};
	char ismin[3][4]={0};
	char yes=0;
	int re[4]={0},col[4]={0};

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			scanf("%d",&data[i][j]);
			}
		}


	for (int i = 0; i < 3; ++i)
	{
		findmax(data[i],re);
		for (int j = 0; j < 4; ++j)
		{
			if(re[j]) 
				ismax[i][j]=1;
		}
	}

	for (int i = 0; i < 4; ++i)
	{
		col[0]=data[0][i];
		col[1]=data[1][i];
		col[2]=data[2][i];
		findmin(col,re);
		for (int j = 0; j < 3; ++j)
		{
			if(re[j]) 
				ismax[j][i]=1;
		}
	}

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			if(ismax[i][j]&&ismin[i][j]){
				printf("%d\n",data[i][j]);

				yes=1;}
			}
		}

	if(yes!=1){
		printf("NO");
	}

	return 0;
}