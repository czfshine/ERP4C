#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#include "ctype.h"
#define DEBUG
struct working
{
    char a[21];
    int num;
} word[10000];

int next(FILE * infile,char * word)//得到下一个单词
{
    char ch,i=0;
    while((ch=getc(infile))!=EOF)
        if(isalpha(ch)) 
          word[i++]=tolower(ch);
        else
        {
            if(ch=='-')
                if((ch=getc(infile))=='\n') 
                  continue;
                else 
                  fseek(infile,-1L,SEEK_CUR);
            word[i]='\0';
            return 1;
        }
    return 0;
}


int main()
{
    FILE *fp;
    fp=fopen("case1.in","r");
    if(fp==NULL) return 0;
    char w[21],ch,ah;
    int i,f,m,j,k,t,min;
    i=0;
    m=0;
    k=1;
    while(next(fp,w)){
  printf("%s\n",w);
    for(j=0; j<k; j++) //与已存在的进行对比，防止有重复
    {
        if(strcmp(w,word[j].a)==0)
        {
            m=1;
       }

        if(m) {word[j].num++;m=0;break;}
       
    }

     if(!m)
        {
            word[k].num=1;
            strcpy(word[k].a,w);
            k++;//存入新单词
            m=0;
        }
  }

    for(i=0; i<k&&i<5; i++) //输出已有单词中前5个最多的单词
    {
        t=0;
        while(word[t].num==0) t++;
        for(j=0; j<k; j++)
        {
            if(word[j].num>word[t].num) t=j;
            else if(word[j].num==word[t].num)
            {
                if(strcmp(word[j].a,word[t].a)<0) t=j;
            }
        }

        if(strlen(word[t].a)>0){
        printf("%s %d\n",word[t].a,word[t].num);
        word[t].num=0;}
        else{
          word[t].num=0;
          i--;
        }
    }
    
    fclose(fp);
    return 0;
}
