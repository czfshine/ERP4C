/*

**************************************
11128 字符串与指针
**************************************
Description

请写出下列程序的运行结果

#include<stdio.h>

int main( )

{   char   string[30]="How_are_you" ;

	char   *p=&string[0],   *p2=string+8;

    printf("%s,%s\n" , p , p2 ) ;

}

 

程序运行结果为：


**************************************
Author0*/
#include<stdio.h>
int main( )
{   char   string[30]="How_are_you" ;
	char   *p=&string[0],   *p2=string+8;
    printf("%s,%s\n" , p , p2 ) ;
}