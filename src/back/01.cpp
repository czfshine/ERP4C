#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
void method_two()
{
    int space;
    int n;
    int i,j;
    printf("�����뱳������������װ��Ʒ����������ͣ���\n");
    scanf("%d",&space);
    printf("��������Ʒ�ĸ�����\n");
    scanf("%d",&n);
    int v[n+1];//��ֵ
    int w[n+1];//����
    int f[n+1][space+1];

       memset(v,0,sizeof(v));
    memset(w,0,sizeof(w));
    memset(f,0,sizeof(f));

    printf("������������Ʒ�ļ�ֵ\n");
    for(i=1;i<=n;i++)
    scanf("%d",&v[i]);
    printf("������������Ʒ������\n");
    for(i=1;i<=n;i++)
    scanf("%d",&w[i]);



    for(i=1;i<=n;i++)//�����Ʒ���뱳��
    {
        for(j=0;j<=space;j++)//�ٶ�������ͬ�����������ͬʱ����Ϊi�����ƣ�f[i][j]��ֵ�Ǻ���һ��f[i][j]��أ���jѭ������������
        {
            f[i][j]=(i==1?0:f[i-1][j]);//i=n�Ǳ߽�������f[i-1][j]����һ�εó��Ľ��
            if(j>=w[i])f[i][j]=max(f[i][j],f[i-1][j-w[i]]+v[i]);//f[i][j]����һ��ʽ�����Ѿ�����ֵΪf[i+1][j]��ֵ


        }
    }
    for(i=0;i<=n;i++)//�����Ʒ���뱳��
    {
        for(j=space;j>=0;j--)//�ٶ�������ͬ�����������ͬʱ����Ϊi�����ƣ�f[i][j]��ֵ�Ǻ���һ��f[i][j]��أ���jѭ������������
        {
        printf("%d ",f[i][j]);
    }
    printf("\n");

}




}


int main(){

    method_two();
}
