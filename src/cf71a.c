#include <stdio.h>
#include <string.h>
int main(){

	int n,len,i;
	scanf("%d",&n);\
	char strings[n][100];
	for (i=0;i<n;i++){

		scanf("%s",strings[i]);
	}

	

	for(i=0;i<n;i++){
		len=strlen(strings[i]);
		if(len<=10){
			printf("%s\n",strings[i]);
		}else{
			printf("%c%d%c\n",strings[i][0],len-2,strings[i][len-1]);
		}
	}
	return 0;
}