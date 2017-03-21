#include "iostream"
#include "algorithm"
#include "time.h"
#include "cstdio"
#define N 2000000

//n分别使用1000,2000,3000,....,10000做实验
#define n 10
using namespace std;
int data[2000010];
int main()
{
    int i;
    unsigned t=clock();
    freopen("data.txt","r",stdin);
    for(i=0; i<N; i++) scanf("%d",&data[i]);
    sort(data, data+N);
    //the following costs much time
    //for(i=0; i<n; i++)
    //    cout<<data[i]<<" ";
    cout<<endl<<"time:"<<clock()-t<<endl;
}