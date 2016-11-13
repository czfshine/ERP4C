/*

**************************************
1098 [填空]链表结点的插入
**************************************
Description

完成插入链表结点的函数(按学号顺序)，并调试通过、提交。
**************************************
Sample Input

3			（3 students）

1			（code of no.1 student）

98			（score of no.1 student）

3			（code of no.2 student）

99			（score of no.2 student）

5			（code of no.3 student）

87			（score of no.3 student）

4			（code of no.3 student needs be inserted）

77			（score of no.3 student needs be inserted）


**************************************
Sample Output

       1      98

       3      99

       5      87

       1      98

       3      99

       4      77

       5      87


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

struct student *insert(struct student *head, struct student *stud) 
{   
	 struct student *p1=NULL,*p2=NULL; 
     int i;

     p1=head;

     while(p1!=NULL)
     {      
     	if(p1->num >= stud-> num ){
     		if(p2==NULL){
     			stud->next=p1;
     			return stud;
     		}else{

     			p2->next=stud;
     			stud->next=p1;
     			return head;
     		}
     	}
     	p2=p1;
     	p1=p1->next;
     } 
     p2->next=stud;
     return head;

} 

main() 
{ 
    struct student *head,*stu; 
    int n; 
    scanf("%d",&n);    
    head=create(n); 
    print(head); 
    stu=(struct student *)malloc(LEN); 
    scanf("%ld",&stu->num);         
    scanf("%d",&stu->score);     
    stu->next = NULL; 
    head=insert(head,stu); 
    print(head); 
} 
