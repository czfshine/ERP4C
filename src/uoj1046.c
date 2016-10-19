#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "math.h"

#define max(x,y) ((x)>(y))?(x):(y)
struct longnum{
    const int mod;
    int dlen;
    int nums[100],len;
};

void numinit(struct  longnum nums[] ,char str[]){
    int L=strlen(str);
    nums[0].len=L/ nums[0].dlen;

    if(L%nums[0].dlen) nums[0].len++;

    int index=0;
    int i,j;
    for (i=L-1;i>=0;i-=nums[0].dlen){
        int t=0;
        int k=i-nums[0].dlen+1;
        if(k<0) k=0;
        for(j=k;j<=i;j++)
        t=t*10+str[j]-'0';
    nums[0].nums[index++]=t;
    }
}

void output(struct longnum num){
    printf("%d",num.nums[num.len-1]);
    int i=0;
    for(i=num.len-2;i>=0;i--)
        printf("%04d",num.nums[i]);
    printf("\n");
}

struct longnum add(struct longnum num1,struct longnum num2){
    struct longnum res={10000,4,{0},0};
    int i;
    res.len=max(num1.len,num2.len);

    for (i=0;i<res.len;i++){
        res.nums[i]=0;
    }

    for (i=0;i<res.len;i++){
        res.nums[i]+=((i<num1.len)?num1.nums[i]:0)+((i<num2.len)?num2.nums[i]:0);
        res.nums[i+1]+=res.nums[i]/res.mod;
        res.nums[i]%=res.mod;
    }
    if(res.nums[res.len]) res.len++;

    return res;
}
int main(){
    char str[81];
    struct longnum num1[1]={{10000,4,{0},0}},num2[1]={{10000,4,{0},0}};
    //struct longnum res;
    scanf("%s",str);
    numinit(num1,str);

    scanf("%s",str);
    numinit(num2,str);
    output(add(num1[0],num2[0]));
    return 0;

}

