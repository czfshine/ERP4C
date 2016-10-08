#include <stdio.h>
#include <stdlib.h>
int cur=0;
int data[100]={0};
int count;
void add(int num){
	data[cur]=num;
	cur++;
}
int main(){
	int n;
	scanf("%d",&n);
	char str[105]={'W','W'};
	scanf("%s",str+2);
	str[n+2]='W';
	str[n+3]='W';	
	char prech='W',ch;
	int in=0;
	for(int i=1;i<n+5;i++){
		ch=str[i];
		if (ch=='W'){
			if(prech=='B'){
				in=0;
				add(count);
				count=0;
			}
		}else{
			if(prech=='W'){
				in=1;
			}
			count++;
		}
		prech=ch;
	}
	printf("%d\n",cur);
	if(cur){
	for (int j=0;j<cur;j++){
		printf("%d ",data[j]);
	}}
	return 0;
}
