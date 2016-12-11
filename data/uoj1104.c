/*

**************************************
1104 [填空题]链表的倒序
**************************************
Description

下面程序，先创建一个链表，然后调用reverse函数，将链表中各结点变为倒序排列。请完成reverse函数，
**************************************
Sample Input

3			（3 students）

1			（code of no.1 student）

98			（score of no.1 student）

4			（code of no.2 student）

99			（score of no.2 student）

5			（code of no.3 student）

87			（score of no.3 student）


**************************************
Sample Output

       1      98

       4      99

       5      87

       5      87

       4      99

       1      98


**************************************
Author0*/
#include "stdio.h"
#include "malloc.h"
#define LEN sizeof(struct student)

struct student
{
     long num;
     int score;
     struct student *next;
};

struct student *create(int n)
{
     struct student *head=NULL,*p1=NULL,*p2=NULL;
     int i;
     for(i=1;i<=n;i++)
     {  p1=(struct student *)malloc(LEN);
        scanf("%ld",&p1->num);
        scanf("%d",&p1->score);
        p1->next=NULL;
        if(i==1) head=p1;
        else p2->next=p1;
        p2=p1;
      }
      return(head);
}

void print(struct student *head)
{
    struct student *p;
    p=head;
    while(p!=NULL)
    {
        printf("%8ld%8d",p->num,p->score);
        p=p->next;
        printf("\n");
    }
}

struct student *reverse(struct student *head)
{
    struct student * end=NULL,*p,*q,*c;

    p=head;

    while(1){
        while(1){
            if(p->next->next==NULL){
                q=p->next;
                p->next=NULL;
                break;
            }

            p=p->next;
        }

        if(end==NULL){
        end=q;
        c=q;
        }else{
        c->next=q;
        c=q;
        }

        if (p==head){
            c->next=p;
            break;}

        p=head;
    }

    return end;
}

main()
{
    struct student *head,*stu;
    int n;
    scanf("%d",&n);
    head=create(n);
    print(head);
    head=reverse(head);
    print(head);
}
