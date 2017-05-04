
#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b)	for(int i=a;i<b;++i)
#define LL		long long
#define mset(a,b)	memset(a,b,sizeof a)
#define scan(n)	scanf("%d",&n)
const int maxn = 1000006;
const int mod = 1000000007;
const int inv2=(mod+1)>>1;
int modinv6 ;
map<int,int> HASH;

int prime[maxn];
int phi[maxn];

void getP()
{
	phi[1]=1;
	REP(i,2,maxn)
	{
		if(!prime[i])
		{
			phi[i]=i-1;
			prime[++prime[0]]=i;
		}
		for(int j=1;j<=prime[0] && prime[j]<=maxn/i;++j)
		{
			prime[i*prime[j]]=1;
			if(i%prime[j])
			{
				phi[i*prime[j]]=(LL)phi[i]*(prime[j]-1)%mod;
			}
			else
			{
				phi[i*prime[j]]=(LL)phi[i]*prime[j]%mod;
				break;
			}
		}
	}
	REP(i,2,maxn)   phi[i]=(LL)phi[i]*i%mod*i%mod;
	REP(i,2,maxn)	phi[i]=(phi[i]+phi[i-1])%mod;
}

int qmod(LL a,int b)
{
	a%=mod;
	LL ret=1;
	for(;b;b>>=1)
	{
		if(b&1)	ret=ret*a%mod;
		a=a*a%mod;
	}
	return ret;
}

inline LL mul(LL a,LL b)
{
	return a%mod*(b%mod)%mod;
}

inline LL sigma(LL n)
{
	n%=mod;
	return ((n*(n+1))>>1)%mod;
}

inline LL sigma2(LL n)
{
    n%=mod;
    return n*(n+1)%mod*(2*n+1)%mod*modinv6%mod;
}

LL g(LL n)
{
	if(n<maxn)	return phi[n];
	if(HASH.count(n))	return HASH[n];
	LL ret=0;
	for(LL i=2,j;i<=n;i=j+1)
	{
		j=n/(n/i);
		ret+=(sigma2(j)-sigma2(i-1))%mod*g(n/i)%mod;
	}
	ret=sigma(n)*sigma(n)%mod-ret;
	ret%=mod;
	if(ret<0)	ret+=mod;
	HASH[n]=ret;
	return ret;
}

int getans(LL n)
{
	LL ret=0;
	for(LL i=1,j;i<=n;i=j+1)
	{
		j=n/(n/i);
		ret+=mul((j-i+1),g(n/i))%mod;
	}
	ret=mul(ret+n,inv2);
	ret%=mod;
	if(ret<0)	ret+=mod;
	return ret;
}

int main()
{
	getP();
	modinv6=qmod(6,mod-2);
	LL n;
    scanf("%lld",&n);

	cout<<getans(n)<<endl;

    return 0;
}
