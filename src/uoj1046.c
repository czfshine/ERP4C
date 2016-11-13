/*

**************************************
1046 计算高精度加法
**************************************
Description
由键盘输入两个位数很长的整数（一行一个，最多不超过80位），试计算并输出这两个数的和。
**************************************
Sample Input

1234567890123456789353534532453453453434534

987654321098765324534534534534532


**************************************
Sample Output
1234567891111111110452299856987987987969066
**************************************
Hint
注意，一个普通的变量不能保存十多位长的整数
**************************************
Author0*/
#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "math.h"
#define max(x,y) ((x)>(y))?(x):(y)

struct longnum{
    const int mod;
    int nums[100],len,dlen;
};
void numinit(struct  longnum nums[] ,char str[]){
    int L=strlen(str),index=0,i,j;
    nums[0].len=L/ nums[0].dlen;
    if(L%nums[0].dlen) nums[0].len++;
    for (i=L-1;i>=0;i-=nums[0].dlen){
        int t=0,k=i-nums[0].dlen+1; 
        if(k<0) k=0;
        for(j=k;j<=i;j++) t=t*10+str[j]-'0';
        nums[0].nums[index++]=t;
    }
}
void output(struct longnum num){
    printf("%d",num.nums[num.len-1]);
    for(int i=num.len-2;i>=0;i--)
        printf("%04d",num.nums[i]);
    printf("\n");
}
struct longnum add(struct longnum num1,struct longnum num2){
    struct longnum res={10000,{0},0,4};
    int i;
    res.len=max(num1.len,num2.len);
    for (i=0;i<res.len;i++) res.nums[i]=0;
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
    struct longnum num1[1]={{10000,{0},0,4}},num2[1]={{10000,{0},0,4}};
    scanf("%s",str);
    numinit(num1,str);
    scanf("%s",str);
    numinit(num2,str);
    output(add(num1[0],num2[0]));
    return 0;
}