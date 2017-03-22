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
queue<string> lv4;

string temp;
int templv;
int temptime=0;
int usernum;
int users=0;
int read(int now){
	if(now < temptime || users>usernum) return 0;

	do{
		
		if(temp.empty()){

		}else{

			switch(templv){
				case 1:
					lv1.push(temp);break;
				case 2:
					lv2.push(temp);break;
					case 3:
					lv3.push(temp);break;
					case 4:
					lv4.push(temp);break;
			}
		}
		users++;
		if(users<=usernum){
			temp.resize(21); //需要预先分配空间
			scanf("%d%d%s",&temptime,&templv,&temp[0]);
		}
		else
			return 0;
	}while(temptime<=now);

}
int pop(){
//printf("pop");
if(lv4.size()>0){
		printf("%s\n",lv4.front().c_str());
		lv4.pop();
		return 4;
	}

	if(lv3.size()>0){
		printf("%s\n",lv3.front().c_str());
		lv3.pop();
		return 3;
	}

	if(lv2.size()>0){
		printf("%s\n",lv2.front().c_str());
		lv2.pop();
		return 2;
	}

	if(lv1.size()>0){
		printf("%s\n",lv1.front().c_str());
		lv1.pop();
		return 1;
	}
	return 0;
}
int main(int argc, char const *argv[])
{
		int time;
		scanf("%d%d",&usernum,&time);

		for (int i = 0; i <= time ; ++i)
		{	
			read(i);
			//cout<<i<<"\n"<<lv1.size()<<lv2.size()<<lv3.size()<<endl;
			if(i%5==0)
				pop();
		}
		//while(pop()){}
	return 0;
}