#include "stdio.h"
#include "string.h"

#define min(x,y) x<y?x:y
char  str[31];
int end=0;
int vis[31][31]={0};
int is_p(int n)
{
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) return 0;
    }    
    return 1;
}


void print(int s,int e){

	for (int i = s; i <= e; ++i)
	{
		putchar(str[i]);
	}

	printf("\n");
}
int tonum(int s,int c){
	int l=0;
	for (int i = s; i <= c; ++i)
	{
		l=l*10+str[i]-'0';
	}
	return l;
}
int ok=0;
int find(int s){
	//print(s,end);
	//printf("%d %s\n",s,str+s);

	if(s==end){
		if(is_p(tonum(s,s))){
				//print(s,s);
			}
		return vis[s][s]=is_p(tonum(s,s));
	}

	int flag=0;
	for (int i = s+1; i <= (min(end,s+6)); ++i)
	{	
		if(vis[s][i]==0){

			if(is_p(tonum(s,i))){
				print(s,i);
				printf("%d %d",s,i);
				vis[s][i]=find(i);
				if(vis[s][i]==1){
					if(i==end)
					{
						if(!ok){
							printf("YES");
							ok=1;
						}
					}
					flag=1;
				}
			}
		}
	}
	if(end-s>6){
		vis[s+6][end]=find(s+6);
		if(vis[s][end]==1){
					flag=1;
		}
	}

	if(flag){
		return 1;
	}
	else
		return -1;
}
int main(int argc, char const *argv[])
{	
	scanf("%s",str);
	end=strlen(str);
	find(0);
	if(!ok)
		printf("NO");

	return 0;
}