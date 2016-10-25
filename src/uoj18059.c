#include <stdio.h> 

struct data 
{   int num;
    char name[10];
    float score[3];
    float a;
}; 

int main() 
{ 
    int i,j; 
    struct data stu[10],tmp; 
    for(i=0; i<10; i++) 
    { 
        scanf("%d %s %f %f %f",&stu[i].num, stu[i].name, stu[i].score, stu[i].score+1, stu[i].score+2);
        stu[i].a=(stu[i].score[0]+stu[i].score[1]+stu[i].score[2])/3.0;
    } 
    for(i=0; i<9; i++) 
        for(j=0; j<9-i; j++) 
        { 
            if(stu[j].a<=stu[j+1].a) {
                tmp=stu[j];
                stu[j]=stu[j+1];
                stu[j+1]=tmp;
            }
        } 
    for(i=0; i<10; i++) 
    { 
        printf("%d %s %.0lf %.0lf %.0lf\n", stu[i].num, stu[i].name, stu[i].score[0], stu[i].score[1], stu[i].score[2]); 
    } 
    return 0; 
} 