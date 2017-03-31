/*coding=utf-8
* NAME    :The EPR system for C.(EPR4C)
* DESP    :C语言版进销存系统
* AUTHOR  :CZFSHINE
* TIME    :2017/03/31 13:39
* LICENSE :MIT License
*/
#include <stdio.h>

/*******const***********/
enum Tstatus {PASS,FAIL};
#define MAXID (1<<31)
#define MAXCOUNT (1<<31)
struct info
{
	char * name;
	char * namelen;
	char * namecoding;

};
struct good
{
	int ID;
	int count;
	info i;
};

void in(int ID,int count);
void out(int ID,int count);
void modifid(int ID,info i);
void new(info i,int count)
/*******TEST************/

Tstatus T_maxid(){

	return PASS;
}
Tstatus T_maxcount(){

	return PASS;
}

/*************LOGIC************/
int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}