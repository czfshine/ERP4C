#include <stdio.h>
#include <queue>
#include <vector>
#include <utility>

#include <string>
#include <stack>

typedef user pair<int,string>

stack<string> lv1;
stack<string> lv2;
stack<string> lv3;

string temp;
int templv;
int read(int now){

	int t,n;
	string name;
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

	}while(t>now);



}
int main(int argc, char const *argv[])
{

	
	
	return 0;
}