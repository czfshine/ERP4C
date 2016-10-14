#include <stdio.h>

struct DATE
{
    int year;
    int month;
    int day;
};

int days(struct DATE date)
{
    int days[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    int day=0,i;

    if(date.year%4==0 && date.year%100!=0 || date.year%400 ==0){
        days[1]=29;
    }
    for(i=0;i<date.month-1;i++){
        day+=days[i];
    }
    day+=date.day;

    return day;
}

int main()
{
    struct DATE d;
    scanf("%d-%d-%d", &d.year, &d.month, &d.day);
    printf("%d", days(d));
}
