#include <stdio.h>

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
void newgood(info i,int count);
