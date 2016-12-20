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
    while(ch!=EOF){

   i=0;
  
  while((ch=getc(fp))!=EOF){
    if(isalpha(ch)){
      w[i++]=tolower(ch);
      
    }else{
      if(ch!='-'){
      w[i]='\0';
      break;}
    }

    if(ch=='-'){
      if((ch=getc(fp))=='\n'){
        continue;
      }else{
        fseek(fp,-1L,SEEK_CUR);
        w[i]='\0';
        break;
      }
      
    }
  }
  if(i>0){
    w[i]='\0';
    return 1;
  }
printf("%s".w);
    for(j=0; j<k; j++) //与已存在的进行对比，防止有重复
    {
        printf("%s,%s\n",w,word[j].a);
        if(strcmp(w,word[j].a)==0)
        {
            m=1;
       }

        if(m) {word[j].num++;break;}
       
    }

     if(m)
        {
            word[k].num=1;
            strcpy(word[k].a,w);
            k++;//存入新单词
            m=0;
        }
  }


#ifdef DEBUG
    for (int jj = 0; jj < k; ++jj)
    {
        printf("%s,%d\n",word[jj].a,word[jj].num);
    }
#endif

    for(i=0; i<k&&i<5; i++) //输出已有单词中前5个最多的单词
    {
        t=0;
        while(word[t].num==0) t++;
        for(j=0; j<i; j++)
        {
            if(word[j].num>word[t].num) t=j;
            else if(word[j].num==word[t].num)
            {
                if(strcmp(word[j].a,word[t].a)<0) t=j;
            }
        }
    }
    printf("%s %d\n",word[t].a,word[t].num);
    word[t].num=0;
    fclose(fp);
    return 0;
}
