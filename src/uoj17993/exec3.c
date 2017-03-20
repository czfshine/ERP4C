#include "iostream"
#include "algorithm"
#include "time.h"
#include "cstdio"
#define N 2000000
//n分别使用1000,2000,3000,....,10000做实验
#define n 1888888
using namespace std;
int c[2000010];
int main()
{
    int i,j,v;
    unsigned t=clock();
    freopen("data.txt","r",stdin);
    for(i=0; i<n; i++) c[i]=100000000;
    for(i=0; i<N; i++)
    {
        scanf("%d",&v);
        for(j=n-1; j>=0; j--)
        {
            if(c[j]>v)
                c[j+1]=c[j];
            else
                break;
        }
        c[j+1]=v;
    }
    //the following costs much time
    //for(i=0; i<n; i++)
    //    cout<<c[i]<<" ";
    cout<<endl<<"time:"<<clock()-t<<endl;
}