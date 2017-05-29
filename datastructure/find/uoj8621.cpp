#include"malloc.h" /* malloc()�� */
#include"stdio.h"
#include"stdlib.h"

typedef int ElemType;
typedef struct /*��̬���ұ��˳��洢�ṹ */
{
    ElemType *elem; /* ����Ԫ�ش洢�ռ��ַ������ʱ��ʵ�ʳ��ȷ��䣬0�ŵ�Ԫ���� */
    int length; /* ���� */
} SSTable;

void Creat_Seq(SSTable &ST,int n)
{
    /* �������: ����һ����n������Ԫ�صľ�̬˳����ұ�ST(������������r) */
    int i,temp;
    ST.elem=(ElemType *)malloc((n+1) * sizeof(ElemType)); /* ��̬����n������Ԫ�ؿռ�(0�ŵ�Ԫ����) */
    if(!(ST).elem)
    {
        printf("ERROR\n");
        exit(0);
    } /*�ڴ����ʧ�ܽ�������*/
    for(i=1; i<=n; i++)
    {
        scanf("%d",&temp);
        *(ST.elem+i)=temp; /* ���θ�ֵ��ST */
    }
    ST.length=n;
}

int Search_bin(SSTable &ST,ElemType key)
{
    /* ��˳���ST��˳�������ؼ��ֵ���key������Ԫ�ء����ҵ�������ֵΪ */
    /* ��Ԫ���ڱ��е�λ�ã�����Ϊ0���㷨9.1 */

    int l,r,mid;

    l=1;
    r=ST.length;
    mid=(r+l)/2;

    while(l<=r)
    {
        //  printf("%d%d%d\n",l,mid,r);

        if(ST.elem[mid]==key)
        {
            return mid;
        }
        if(key>ST.elem[mid])
        {
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
        mid=(r+l)/2;
    }

    // printf("%d%d%d",ST.elem[r],r,key);

    return 0;

}



main()
{
    SSTable ST;
    int loc,key;
    int n;
    scanf("%d",&n);
    Creat_Seq(ST,n);
    //printf("Please input the key value��");
    scanf("%d",&key);
    loc = Search_bin(ST,key);
    if(loc!=0)
        printf("The element position is %d.\n",loc-1);
    else
        printf("The element is not exist.\n");
}
