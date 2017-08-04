/*
 �ú���ʵ�����¶����������㷨�� ��
 1��	�����½�� ��
 2��	ǰ�����򡢺������������ ��
 3�� ��������ķǵݹ��㷨 ��
 4��	��α��������� ��
 5��	�ڶ������в��Ҹ����ؼ���(��������ֵΪ�ɹ�1,ʧ��0)


�����ʽ
��һ�У�׼�������Ľ�����n
�ڶ��У�����n���������ÿո�ָ�
�����У���������ҵĹؼ���
�����У���������ҵĹؼ���
�����У����������Ĺؼ���


�����ʽ
��һ�У��������������������
�ڶ��У��������������������
�����У��������ĺ����������
�����У����ҽ��
�����У����ҽ��
������~�ڰ��У������½���Ķ��������ȡ��С����������
�ھ��У������½���Ķ������������������(�ǵݹ��㷨)
��ʮ�У������½���Ķ������Ĳ�α�������


��������
7
40 20 60 18 50 56 90
18
35
30


�������
40 20 18 60 50 56 90
18 20 40 50 56 60 90
18 20 56 50 90 60 40
1
0
40 20 18 30 60 50 56 90
18 20 30 40 50 56 60 90
18 30 20 56 50 90 60 40
18 20 30 40 50 56 60 90
40 20 60 18 30 50 90 56

*/


#include <cstdio>
#include <malloc.h>
#include <iostream>

#define OK  1
#define ERROR  0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int  Status;
typedef int  ElemType;


using namespace std;


//core
struct BSTree
{
    ElemType data;
    struct BSTree *lchild,*rchild;//���Һ���ָ��

    BSTree()
    {
        rchild=lchild=nullptr;
    }
    void PrintElement()
    {
        cout<<data<<" ";
    }
    Status PreOrderTraverse()
    {
        PrintElement();
        lchild!=nullptr && lchild->PreOrderTraverse();
        rchild!=nullptr && rchild->PreOrderTraverse();
        return OK;
    }
    Status Leave()
    {
        if(lchild == nullptr  && rchild ==nullptr)
            return true;
        return false;
    }
    Status Search(ElemType t,BSTree * &p )
    {   p=this;
        if(data==t) {  return true;}
        if(t<data &&  lchild !=nullptr) return lchild->Search(t,p);
        if(t>data &&  rchild !=nullptr) return rchild->Search(t,p);
        return false;
    }
    Status Insert(ElemType k){
        BSTree *p;
        if(!Search(k,p)){
            BSTree * s=(BSTree *) malloc(sizeof (BSTree));
            s->data=k; s->lchild=s->rchild=nullptr;

            if(k<p->data) p->lchild=s;
            else p->rchild=s;
            return true;
        }
        return false;

    }
    Status InOrderTraverse(){

        lchild!=nullptr && lchild->PreOrderTraverse();
        PrintElement();
        rchild!=nullptr && rchild->PreOrderTraverse();
        return OK;
    }
    Status PostOrderTraverse( ){

        lchild!=nullptr && lchild->PreOrderTraverse();
        rchild!=nullptr && rchild->PreOrderTraverse();
        PrintElement();
        return OK;
    }
};

class BST{

private:
    BSTree T;
    int count=0;
public:
    void insert(ElemType k){
        if(!count){
            T.data=k;
        }else{
            T.Insert(k);
        }
        count++;
    }

    void PreOrder(){
        T.PreOrderTraverse();
        cout<<endl;
    }
    void PostOrder(){
        T.PostOrderTraverse();
        cout<<endl;
    }
    void InOrder(){
        T.InOrderTraverse();
        cout<<endl;
    }
};


int main()   //������
{
    BST T;

    int n;
    cin>>n;
    int t;
    while(n--){
        cin>>t;
        if(t==18){
            1+1;
        }
        T.insert(t);
        T.PreOrder();
        T.InOrder();
        T.PostOrder();
    }


}//main
