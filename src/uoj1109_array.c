#include "stdio.h" 
#include "math.h" 
#include "string.h" 
#include "stdlib.h" 

char words[10001][21];
int  count[10001];

int next(FILE * infile,char * word){

}
FILE* open(char * filename){

}

void counter(char * word){

}

void sort(){

}

void print(){

}
main() 
{ 
	char filename[]="case1.in";
	char tmp_w[21];

	FILE * infile;
	infile=open(filename);

	while(next(infile,tmp_w))
		counter(tmp_w);

	sort();
	print();
         
} 
