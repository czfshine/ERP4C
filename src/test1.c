#include<stdio.h>
#define quit 'q'
#define stars "***********************"
char menu(void);
int main(void)
{
    float num1,num2,num3,num4,num5,num6,num7,num8;
    char character;
    while((character=menu())!=quit)
    {
    	printf("%c",character);
        if(character=='a')
        {
            printf("Enter first number:\n");
            while(scanf("%f",&num1)!=1)
                printf("Please enter a number\n");
            printf("Enter second number:\n");
            while(scanf("%f",&num2)!=1)
                printf("Please enter a number\n");
            printf("%0.1f + %0.1f = %0.1f",num1,num2,num1+num2);
        }
        if(character=='s')
        {
            printf("Enter first number:\n");
            while(scanf("%f",&num3)!=1)
                printf("Please enter a number\n");
            printf("Enter second number:\n");
            while(scanf("%f",&num4)!=1)
                printf("Please enter a number\n");
            printf("%0.1f - %0.1f = %0.1f",num3,num4,num3-num4);
        }
        if(character=='m')
        {
            printf("Enter first number:\n");
            while(scanf("%f",&num5)!=1)
                printf("Please enter a number\n");
            printf("Enter second number:\n");
            while(scanf("%f",&num6)!=1)
                printf("Please enter a number\n");
            printf("%0.1f * %0.1f = %0.1f",num5,num6,num5*num6);
        }
        if(character=='d')
        {
            printf("Enter first number:\n");
            while(scanf("%f",&num7)!=1)
                printf("Please enter a number\n");
            printf("Enter second number:\n");
            scanf("%f",&num8);
            while((scanf!=1)&&(num8!=0))
                printf("Please enter a number expect 0\n");
            printf("%0.1f / %0.1f = %0.1f",num7,num8,num7/num8);
            scanf("%f",&num8);
        }
    }
    printf("Thank you and goodbye.\n");
    return 0;
}
char menu(void)
{
    char ch;
    printf("\n%s%s\n",stars,stars);
    printf("Enter the operation of your choice:\n");
    printf("a.add\n");
    printf("s.subtract\n");
    printf("m.multiply\n");
    printf("d.divide\n");
    printf("q.quit\n");
    printf("%s%s\n",stars,stars);
    ch=getchar();
    while(getchar()!='\n')
        continue;
    while(ch!='a'&&ch!='s'&&ch!='m'&&ch!='d'&&ch!='q')
    {

        printf("Enter an appointed character:\n");
        ch=getchar();
        while(getchar()!='\n')
            continue;

    }
    return ch;

}
