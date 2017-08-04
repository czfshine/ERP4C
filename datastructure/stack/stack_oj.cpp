
typedef int SElemType; // ����ջԪ������
typedef int Status; // Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK��

struct SqStack
{
    SElemType *base; // ��ջ����֮ǰ������֮��base��ֵΪNULL
    SElemType *top; // ջ��ָ��
    int stacksize; // ��ǰ�ѷ���Ĵ洢�ռ䣬��Ԫ��Ϊ��λ

    SqStack()
    {
// ����һ����ջS����ջԤ�����СΪSTACK_INIT_SIZE
        base=(SElemType*)malloc(STACK_INIT_SIZE*sizeof(SElemType));
        top=base;
        stacksize=STACK_INIT_SIZE;
    }

    Status Push(SElemType e)
    {
// ��ջS�в���Ԫ��eΪ�µ�ջ��Ԫ��
        if(top-base>=stacksize)
        {
            base=(SElemType*)realloc(base,(stacksize+STACKINCREMENT)*sizeof(SElemType));
            if(!base) return ERROR;
            top=base+stacksize;
            stacksize+=STACKINCREMENT;
        }
        *top++=e;
        return OK;
    }

    Status Pop()
    {
// ��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR
        if(top==base) return ERROR;
        --top;
        return OK;
    }

    Status GetTop(SElemType &e)
    {
// ��ջ���գ�����e����S��ջ��Ԫ�أ�������OK�����򷵻�ERROR
        if(top==base) return ERROR;
        e=*(top-1);
        return OK;
    }

    int StackLength()
    {
// ����ջS��Ԫ�ظ���

        return top-base;;
    }

    Status StackTraverse()
    {
// ��ջ����ջ���������ջ�е�ÿ��Ԫ��
        SElemType *p = (SElemType *)malloc(sizeof(SElemType));
        p = top;
        if(top==base)printf("The Stack is Empty!");
        else
        {
            printf("The Stack is: ");
            p--;
            while(p>=base)
            {
                printf("%d ", *p);
                p--;
            }
        }
        printf("\n");
        return OK;
    }


}; // ˳��ջ

