#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>

using namespace std;
int main()
{
    int n,vip,time,i=99999,p=0,o=0,timemax;
    string name;
    priority_queue<pair<int, string> > pq;
    scanf("%d%d",&n,&timemax);
    while(n--){
        cin>>time>>vip>>name;
        while(time-p>0){
            if(!pq.empty()){
                cout<<pq.top().second<<endl;
                pq.pop();
                
            }
            o++;
            p+=5;
        }
        pq.push(make_pair(vip*100000+i,name));
        i--;
    }
    while(!pq.empty()&&o<(timemax/5+(timemax%5 ==0?0:1))){
        cout<<pq.top().second<<endl;
        pq.pop();
        o++;
    }
    return 0;
}