#include <stdio.h>
#include <queue>
#include <vector>
#include <utility>
#include <iostream>
#include <string>
#include <stack>

using namespace std;

stack<string> lv1;
stack<string> lv2;
stack<string> lv3;

string temp;
int templv;
int temptime=0;

int read(int now){
	if(now < temptime) return 0;

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
			}
		}
		cin >>temptime>>templv>>temp;
	}while(temptime>=now);



}
int main(int argc, char const *argv[])
{
		whlie(1){
			read();
			cout<<lv1.size()<<lv2.size()<<lv3.size();
		}
	 
	
	return 0;
}