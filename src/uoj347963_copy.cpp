#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <cstring>
#include <string>
#include <vector>
#include <iomanip>
#include <cmath>
#include <list>
#include <bitset>

using namespace std;

#define ll long long 
#define lson l,mid,id<<1
#define rson mid+1,r,id<<1|1

typedef pair<int, int>pii;
typedef pair<ll, ll>pll;
typedef pair<double, double>pdd;

const double eps = 1e-6;
const ll  LINF = 0x3f3f3f3f3f3f3f3fLL;
const int INF = 0x3f3f3f3f;
const double FINF = 1e18;

#define x first
#define y second

#define REP(i,j,k) for(int i =(j);i<=(k);i++)
#define REPD(i,j,k) for(int i =(j);i>=(k);i--)
#define print(x) cout<<(x)<<endl;
#define IOS ios::sync_with_stdio(0);cin.tie(0);


#include "stdio.h"
#include "malloc.h"
#define TRUE 1
#define FALSE 0
#define OK  1
#define ERROR  0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int  Status;
typedef char  ElemType;

typedef struct BiTNode{
  ElemType data;
  struct BiTNode *lchild,*rchild;//左右孩子指针
}BiTNode,*BiTree;

Status CreateBiTree(BiTree &T) {  // 算法6.4
  // 按先序次序输入二叉树中结点的值（一个字符），’#’字符表示空树，
  // 构造二叉链表表示的二叉树T。
  char ch;
  scanf("%c",&ch);
  if (ch=='#') T = NULL;
  else {
    if (!(T = (BiTNode *)malloc(sizeof(BiTNode)))) return ERROR;
    T->data=ch; // 生成根结点
    CreateBiTree(T->lchild);// 构造左子树
    CreateBiTree(T->rchild); // 构造右子树
  }
  return OK;
} // CreateBiTree


int Onchild(BiTree T)
{
    int num1,num2,n=0;
    if(T==NULL) return 0;
    else
    {
        if((T->lchild==NULL&&T->rchild!=NULL)||(T->lchild!=NULL&&T->rchild==NULL))   n=1;
        num1=Onchild(T->lchild);
        num2=Onchild(T->rchild);
        return (num1+num2+n);
    }
}


BiTree T;

void Init(){

    CreateBiTree(T);

	return ;
}

void Solve(){
	
	printf("%d",Onchild(T));

	return ;
}

int main(){

	freopen("uoj347963_copy.in","r",stdin);



	Init(),Solve();
	return 0;
}