#include <stdlib.h>
#include "string.h"
#include <stdio.h>


#define DEBUG 1

struct danci
{
    int num;
    char word[21];
};

static int k=0;//结构体数组的组数
void bijiaocishu(struct danci a[]);
void zidian(struct danci a[]);
int main()
{
    struct danci a[10000]={0};
    FILE *fp;
    fp=fopen("case1.in","r");
    if(fp==NULL)
        exit(0);
    char ch[200000];int i=0,t[200000];   //1代表是字母，0不是
    while((ch[i]=fgetc(fp))!=EOF)
    {
        if(ch[i]<='Z'&&ch[i]>='A'||ch[i]<='z'&&ch[i]>='a')
            t[i]=1;

        if(ch[i]<='Z'&&ch[i]>='A')
            ch[i]+=32;
        if(ch[i]=='\n'&&ch[i-1]=='-')
           {t[i]=3; continue;}

        if(!(ch[i]<='Z'&&ch[i]>='A'||ch[i]<='z'&&ch[i]>='a'))
        {
            if(ch[i]=='-'&&ch[i+1]=='\n')
            {
                t[i]=3;
            }
            else t[i]=0;
        }
        i++;
    }
    t[i]=2;//表示全文结束
    fclose(fp);   /*把连字符和回车的特殊情况写3当做是字母*/

    #ifdef DEBUG
    printf("array t[]:\n")''
    int debug_j=0;
    for (int debug_j = 0; debug_j < i; ++debug_j)
    {
        printf("%d ",t[debug_j]);
    }
    printf("\n");
    #endif
    int j=0,g,temp;
    char wordtry[21];
    for(i=0;t[i]!=2;i++)   //k代表结构体第几组
    {

        if(t[i]==0&&t[i-1]==1)  //遇到前一个是字母这个不是字母
        {
            int dancitop=0,toptry=0;
            temp=j;

            while(ch[j]<='z'&&ch[j]>='a'||ch[j]<='Z'&&ch[j]>='A') //假设了第一个字符就是字母来开始
            {
                wordtry[toptry++]=ch[j++];   //先把单词存放在暂时的用于比对储存的
            }

            int bijiao=0; //比较为0说明是新单词

                for(g=0;g<k;g++)   //依次比对每一个结构体
                {
                    if(strcmp(wordtry,a[g].word)==0)
                     {
                        bijiao=1;
                        a[g].num+=1;
                        break;
                     }
                }
                if(bijiao==0)
                {
                    while(ch[temp]<='z'&&ch[temp]>='a'||ch[temp]<='Z'&&ch[temp]>='A')
                    a[k].word[dancitop++]=ch[temp++];

                    k++;//注意如果全部结束此时k+1了
                }

        }
        if(t[i]==0&&t[i+1]==1)  //储存下一个单词开头的位置
        {
            j=i+1;
        }
    }

    if(k<=4)
    {
        for(k=0;k<4;k++)
        printf("%s %d\n",a[k].word,a[k].num);
    }
    else
    {
        bijiaocishu(a);
        zidian(a);
        for(g=0;g<k;g++)
            printf("%s %d\n",a[g].word,a[g].num);
    }
    return 0;

}

void bijiaocishu(struct danci a[])
{
    int i,j;
    struct danci temp;

    for(i=0;i<k-1;i++)
    {
        for(j=0;j<k-1-i;j++)
        if(a[j].num<a[j+1].num)
        {
            temp=a[j];
            a[j]=a[j+1];
            a[j+1]=temp;
        }
    }
}
void zidian(struct danci a[])
{
    struct danci temp;
    int i,j,g;
    for(i=0;i<k-1;i++)
    {
        g=i;
        for(j=i+1;j<k;j++)
        {
              if(a[j].num!=a[j+1].num)
                continue;
              if(strcmp(a[j].word,a[g].word)<0)
              {
                  g=j;
                  temp=a[g];
                  a[g]=a[i];
                  a[i]=temp;
              }

        }
    }
}