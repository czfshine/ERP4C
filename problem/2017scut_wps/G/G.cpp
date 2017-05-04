#include<bits/stdc++.h>
using namespace std;

int n;
double dp[2];
double p;
double getans()
{
    dp[0]=1/p;
    double ret=dp[0];
    for(int i=2,k=1;i<n;++i,k=k^1)
    {

        dp[k]=1/p+(1/p-1)*dp[k^1];
        ret+=dp[k];
    }
    return 2*ret;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
    	scanf("%d%lf",&n,&p);
        printf("%.2f\n",getans());
   
    }
	return 0;
}
