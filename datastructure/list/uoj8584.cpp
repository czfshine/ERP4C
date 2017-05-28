#include <malloc.h>
#include<cstdio>
#include <cstdlib>
#define OK 1
#define ERROR 0

//TODO: return is 0
typedef int Status; // Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK��
typedef int ElemType;
#define MAXQSIZE 100 // �����г���(����ѭ�����У������г���Ҫ��1)
#define MOD(x) ((x+MAXQSIZE)%MAXQSIZE)
struct Queue
{
    ElemType *base; // ��ʼ���Ķ�̬����洢�ռ�
    int front; // ͷָ��,�����в���,ָ�����ͷԪ��
    int rear; // βָ��,�����в���,ָ�����βԪ�ص���һ��λ��

    Queue()
    {
        base=(ElemType *) malloc(sizeof(ElemType)*MAXQSIZE);
        front=rear=0;
    }

    Status DestroyQueue()
    {
        return OK;
    }

    Status ClearQueue()
    {
        return OK;
    }

    int QueueEmpty()
    {
        if(front ==rear)
            return 1;
        return 0;
    }

    int GetLength()
    {
        return MOD(rear-front);
    }


    ElemType  GetHead()
    {   if(front ==rear)return ERROR;
        ElemType e=base[front];
         return e;
        return OK;
    }


    Status EnQueue(ElemType e)
    {
        if(MOD(rear +1) == front) return ERROR;

        base[rear]=e;

        rear =MOD(rear +1);
        return OK;

    }

    ElemType DeQueue()
    {
        if(front ==rear)return ERROR;
        ElemType e=base[front];
        front=MOD(front +1);
        return e;
    }


    Status QueueTraverse()
    {
// �����в��գ���Ӷ�ͷ����β���������������Ԫ�أ�������OK�����򷵻�ERROR.
        int i;
        i=front;
        if(GetLength()==0)printf("The Queue is Empty!");  //�����
        else
        {
            printf("The Queue is: ");
            while(i!=rear)     //�����
            {
                printf("%d ",base[i]);   //�����
                i = MOD(i+1);   //�����
            }
        }
        printf("\n");
        return OK;
    }

};



int main()
{
    int a;
    Queue Q;
    ElemType x, e;
    if(&Q)    // �ж�˳����Ƿ񴴽��ɹ��������
    {
        printf("A Queue Has Created.\n");
    }

    while(1)
    {
        printf("1:Enter \n2:Delete \n3:Get the Front \n4:Return the Length of the Queue\n5:Load the Queue\n0:Exit\nPlease choose:\n");
        scanf("%d",&a);
        switch(a)
        {
        case 1:
            scanf("%d", &x);
            if(!Q.EnQueue(x)) printf("Enter Error!\n"); // �ж�����Ƿ�Ϸ��������
            else printf("The Element %d is Successfully Entered!\n", x);
            break;
        case 2:
            if((e=Q.DeQueue())==0) printf("Delete Error!\n"); // �жϳ����Ƿ�Ϸ��������
            else printf("The Element %d is Successfully Deleted!\n", e);
            break;
        case 3:
            if((e=Q.GetHead())==0)printf("Get Head Error!\n"); // �ж�Get Head�Ƿ�Ϸ��������
            else printf("The Head of the Queue is %d!\n", e);
            break;
        case 4:
            printf("The Length of the Queue is %d!\n",Q.GetLength());  //�����
            break;
        case 5:
            Q.QueueTraverse(); //�����
            break;
        case 0:
            return 1;
        }
    }
}
