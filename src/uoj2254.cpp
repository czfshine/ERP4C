#include <stdio.h>
#include <queue>
#include <vector>
#include <utility>
#include <iostream>
#include <string>
#include <stack>
#include <queue>

using namespace std;

queue<string> lv1;
queue<string> lv2;
queue<string> lv3;

string temp;
int templv;
int temptime=0;
int usernum;
int users=0;
int read(int now){
	if(now < temptime || users>usernum) return 0;

	do{
		printf("test\n");
		if(temp.empty()){

		}else{

			switch(templv){
				case 1:
					lv1.push(temp);break;
				case 2:
					lv2.push(temp);break;
				case 3:
					lv3.push(temp);break;
			}
		}
		users++;
		if(users<=usernum){
			cin >>temptime>>templv>>temp;
		}
		else
			return 0;
	}while(temptime<=now);



}
int main(int argc, char const *argv[])
{
		int time;
		scanf("%d%d",&usernum,&time);
		for (int i = 0; i < time; ++i)
		{	
			read(i);
			cout<<i<<"\n"<<lv1.size()<<lv2.size()<<lv3.size()<<endl;
			
		}
			
			
		
	 
	
	return 0;
}