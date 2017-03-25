#include <cstdio>   
#include <functional>
#include <queue>
#include <vector>

#include <iostream>
#include <utility>
using namespace std;

typedef  pair<int,string> user;

int main(int argc, char const *argv[])
{
	priority_queue<user > pq;

	int usernum;
	int timemax;

	scanf("%d%d",&usernum,&timemax);
	user temp;
	int ttime=-1;
	int lv;
	string name;

	user out;
	/*
	for (int i = 0; i < timemax;i+=5 )
	{	if(ttime>=0) pq.push(temp);
		while(i<=ttime){

			cin>>ttime>>lv>>name;
			temp.first=lv*10000;
			temp.second=name;
			pq.push(temp);
		}

		if(i%5==0){
			if(!pq.empty()){
				out=pq.top();

				print(top.second)

			}
		}

	}
	*/
	int outusernum=0;
	int p=0;//%5
	int ttweight=99999;
	while(usernum--){
        cin>>ttime>>lv>>name;
        
        while(ttime-p>0){
            if(!pq.empty()){
                cout<<pq.top().second<<endl;
                pq.pop();
               
            }
             outusernum++;
            p+=5;
        }
        pq.push(make_pair(lv*100000+ttweight,name));
        ttweight--;
    }

    while(!pq.empty()&&outusernum<(timemax/5+(timemax%5 ==0?0:1))){
        cout<<pq.top().second<<endl;
        pq.pop();
        outusernum++;
    }

	return 0;
}