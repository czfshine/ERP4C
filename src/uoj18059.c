/*

**************************************
18059 学生成绩表
**************************************
Description

输入10个学生，每个学生的数据包括学号、姓名、3门课的成绩。定义结构体类型表示学生类型，输入10个学生的数据，

计算每个学生的平均成绩。按平均成绩由高到低输出所有学生信息，成绩相同时按学号从小到大输出。
**************************************
Input

10个学生信息，每行一个学生
**************************************
Output

如题
**************************************
Sample Input

1 aaa 50 60 70

2 bbb 50 50 50

3 ccc 60 70 80

4 ddd 40 40 40 

5 eee 70 80 90

6 fff 30 30 30 

7 ggg 80 90 100

8 hhh 20 20 20

9 iii 100 100 100

10 jjj 10 10 10




**************************************
Sample Output

9 iii 100 100 100

7 ggg 80 90 100

5 eee 70 80 90

3 ccc 60 70 80

1 aaa 50 60 70

2 bbb 50 50 50

4 ddd 40 40 40 

6 fff 30 30 30 

8 hhh 20 20 20

10 jjj 10 10 10


**************************************
Author0*/
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