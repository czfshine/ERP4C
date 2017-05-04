#include<bits/stdc++.h>
using namespace std;
#define LL			long long
const int maxn = 500005;
LL f[maxn];
void init()
{
	for(LL i=0;i<maxn;++i)
		f[i]=(i+1)*i*(i-1)/6+i;
}

inline int getans(LL n)
{
	int l=1,r=maxn-1;
	while(l<=r)
	{
		int m=(l+r)>>1;
		if(n<=f[m])	r=m-1;
		else 		l=m+1;
	}
	return l;
}

int main()
{
	init();
	LL n;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld",&n);
        printf("%d\n",getans(n));
    }
	return 0;
}
