/*

**************************************
1859 EXOCENTER OF A TRIANGLE
**************************************
Description2
0.0 0.0
9.0 12.0
14.0 0.0
3.0 4.0
13.0 19.0
2.0 -10.0
**************************************
Input9.0000 3.7500
-48.0400 23.3600
**************************************
Output
**************************************
Sample Input
**************************************
Sample Output
**************************************
Hint
**************************************
Source
**************************************
Author0*/
#include <stdio.h> 

struct data 
{ 
    int  num;
    char name[20];
    float score[3];
    float a;
}; 

int main() 
{ 
    int i,j; 
    struct data stu[10],tmp; 
    for(i=0; i<10; i++) 
    { 
        scanf("%d %s %f %f %f", &stu[i].num, &stu[i].name, &stu[i].score[0], &stu[i].score[1], &stu[i].score[2]); 
        stu[i].a=(stu[i].score[0]+stu[i].score[1]+stu[i].score[2])/3.0;
    } 
    for(i=0; i<9; i++) 
        for(j=0; j<9-i; j++) 
        { 
            if(stu[j+1].a<stu[i+1].a){

                tmp=stu[j];
                stu[j]=stu[i];
                stu[i]=tmp;
            }
        } 
    for(i=0; i<10; i++) 
    { 
        printf("%d %f %s %.0lf %.0lf %.0lf \n", stu[i].num,stu[i].a, stu[i].name, stu[i].score[0], stu[i].score[1], stu[i].score[2]); 
    } 
    return 0; 
} 