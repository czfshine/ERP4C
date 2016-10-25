#include "stdio.h" 
//23333333333333333333333
void binary(int n){
  	char b[16]={0};
    sprintf(b,"%o",n);
    int cur=0;
    switch(b[cur]){
    		case'0':printf("");break;
    		case'1':printf("1");break;
    		case'2':printf("10");break;
    		case'3':printf("11");break;
    		case'4':printf("100");break;
    		case'5':printf("101");break;
    		case'6':printf("110");break;
    		case'7':printf("111");break;
    	}
    cur++;
    while(b[cur]!='\0'){
    	switch(b[cur]){
    		case'0':printf("000");break;
    		case'1':printf("001");break;
    		case'2':printf("010");break;
    		case'3':printf("011");break;
    		case'4':printf("100");break;
    		case'5':printf("101");break;
    		case'6':printf("110");break;
    		case'7':printf("111");break;
    	}
    cur++;
    }
}

main() 
{ 
    int n; 
    scanf("%d", &n); 
    binary(n); 
} 