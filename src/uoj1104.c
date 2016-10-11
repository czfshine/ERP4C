#include "stdio.h" 
#include "malloc.h" 
#define LEN sizeof(struct student) 
//TODO
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
	struct student * pre=NULL ,*p=NULL,*temp=NULL,*res=NULL;

	p=head;

	while(p!=NULL){
		if(p->next->next==NULL){
			res=p->next;
			p->next=NULL;
			p=NULL;
		}else{
		p=p->next;}
	}
	temp=res;
	p=head;
	while(p!=NULL){
		if(p->next->next==NULL){
			res->next=p->next;
			res=res->next;
			p->next=NULL;
			if(head->next==NULL){
				res->next=head;
				temp->next=res;
				return temp;
			}
			if(head->next->next==NULL){
				res->next=head->next;
				res=res->next;
			
				res->next=head;
				p=	NULL;
				temp->next=res;
				return temp;
			}else{
			p=head;}
		}else{p=p->next;}
	}

	return res;

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