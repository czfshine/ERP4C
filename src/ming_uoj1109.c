#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define DEBUG
struct working
{
    char a[21];
    int num;
}word[10000];
int main()
{
    FILE *fp;
    fp=fopen("case1.in","r");
    if(fp==NULL) return 0;
    char w[21],ch,ah;
    int i,f,m,j,k,t,min;
    i=0;
    m=0;
    k=0;
    while((ch=fgetc(fp))!=EOF)
    {	
    	#ifdef DEBUG
        printf("input char is:%c\n",ch);
        #endif

        if(ch>='A'&&ch<='Z') ch=ch+32;//小写转化为大写
        if(ch>='a'&&ch<='z')
            {
            w[i]=ch;
            i++;
            }//找一个元素的单词

        else if(ch=='-')
        {
            ah=fgetc(fp);
            if(ah=='\n')
            {
                ch=fgetc(fp);
                if(ch>='a'&&ch<='z')
                      {
                      w[i]=ch;
                      ch=fgetc(fp);
                      i++;
                      }
            }
            else fseek(fp,-1l,SEEK_CUR);
        }
        w[i]=0;
        #ifdef DEBUG
        printf("input char is:%c\n",ch);
        #endif

                      for(j=0;j<i;j++)//与已存在的进行对比，防止有重复
                      {	
                      	//printf("%s,%s",w,word[j].a);
                          if(strcmp(w,word[j].a)==0)
                          {
                              m=1;
                              break;//与已存在的比较
                          }
                        
                        
                          if(m) word[j].num++;
                          else
                          {
                              word[k].num=1;
                              strcpy(word[k].a,w);
                              k++;//存入新单词
                          }

                
                      }

        }

        #ifdef DEBUG
        printf("input end\n");
        #endif

             for(i=0;i<k&&i<5;i++)//输出已有单词中前5个最多的单词
             {
                 t=0;
                 while(word[t].num==0) t++;
                 for(j=0;j<i;j++)
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