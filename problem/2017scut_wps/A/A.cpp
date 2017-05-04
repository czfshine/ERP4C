#include<bits/stdc++.h>
using namespace std;
const int maxn = 1000006;
const int INF = 0x3fffffff;
int main()
{
	int n,a;
	scanf("%d",&n);
	int m=-INF,ans=-INF;
	for(int i=0;i<n;++i)	
	{
		scanf("%d",&a);
		if(a>m)
		{
			ans=m;m=a;
		}
		else if(a<m && a>ans)
		{
			ans=a;
		}
	}
	if(ans==-INF)
		puts("all the same");
	else printf("%d\n",ans);
	scanf("%d",&n);
	return 0;
}
