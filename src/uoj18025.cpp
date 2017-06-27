#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <cstring>
#include <string>
#include <vector>
#include <iomanip>
#include <cmath>
#include <list>
#include <bitset>

using namespace std;

#define ll long long
#define lson l,mid,id<<1
#define rson mid+1,r,id<<1|1

typedef pair<int, int>pii;
typedef pair<ll, ll>pll;
typedef pair<double, double>pdd;

const double eps = 1e-6;
const ll  LINF = 0x3f3f3f3f3f3f3f3fLL;
const int INF = 0x3f3f3f3f;
const double FINF = 1e18;

#define x first
#define y second

#define REP(i,j,k) for(int i =(j);i<=(k);i++)
#define REPD(i,j,k) for(int i =(j);i>=(k);i--)

#define IOS ios::sync_with_stdio(0);cin.tie(0);


#include<stdio.h>
#include<math.h>
#include<string.h>
int ans=0;
int prime[45];
int store[100];
int n,m;
void is_prime()
{
    int k;
    int i;
    prime[0]=prime[1]=0;
    for(m=2;m<45;m++)//��m����2~����m��������ܱ������κ�һ������������mΪ����������Ϊ��������
    {
        k=sqrt(m);
        for(i=2;i<=k;i++)
        if(m%i==0)
        break;
        if(i>k)prime[m]=1;
        else
        prime[m]=0;
    }
}

void print(){
    for(int i=0;i<20;i++){
        printf("%d ",store[i]);
    }
    printf("\n");
}
void success(int t)
{
    //printf("A:%d %d\n",n,m);
    int i;
    int total=0;
    if(t>n)//�������nλ˵������ɹ�,һֱ���������Ż����t>n
    {
        ans++;
        //print();
        //printf("enter\n");
        return;
    }
    if(t>=m)
    for(i=t-1;i>t-m;i--)//��Χ��1~m-1
    total+=store[i];//����ǰ m-1λ��ֵ
    for(i=0;i<=9;i++)//ÿһλ����ʹ0~9��������
    {
        if(prime[total+i]|| t<m) //���������һλ��һ�����������±���
        {
            store[t]=i;
            success(t+1);
            //printf("C\n");
        }
    }


}
int main()
{
    int k;
    int i;
    is_prime();
    //prime[0]=1;
    scanf("%d",&k);
    for(int i=0;i<k;i++)
    {
        ans=0;
        scanf("%d %d",&n,&m);
        success(1);//�ӵ�һλ��ʼö�٣������������
        printf("%d\n",ans);
    }
}
