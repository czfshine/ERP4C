#include <cstdio>
#include <algorithm>
#include <string>
#include <map>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

map <string ,int> dict;
bool end=false;
//debug
#ifdef LOCAL
#define fp stdin 
#else
FILE *fp;
#endif

char last=0;
char ch;
struct node{
	string s;
	int count;
};
struct cmp{
	bool operator() (const node a, const node b) const { 
		return a.count < b.count;
	}
};

struct{
	int mincount;
	char count;

	priority_queue<node,vector<node>,cmp>pq;

	void push(string str){
		if(count<5){
				node t;
				t.s=str;
				t.count=dict[str];
				pq.push(t);
				count++;
				mincount=min(dict[str],mincount);
			}else{
		if(dict[str]>mincount){
			mincount=dict[str];
			cout<<str<<endl;
			
				pq.top();
				pq.pop();
				node t;
				t.s=str;
				t.count=dict[str];
				pq.push(t);
			}
		}
	}

	void print(){
		for (int i = 0; i < 5; ++i)
		{
			node t;
			t=pq.top();
			pq.pop();
			cout<<t.s<<"=is="<<t.count<<endl;
		}
	}
}listt;
string getword(){
	
	string s;

	if (last){
		s.push_back(last);
		last=0;
	}

	while((ch=getc(fp))!=EOF){
		//printf("is :%c\n",ch);
		if(ch=='-'){

			if((ch=getc(fp))=='\n'){
				continue;
			}else{
				last=ch;
				break;
			}

		}

		if(ch>='A'&&ch<='Z' || ch>='a'&&ch<='z')
			s.push_back(ch);
		else
			break;

	}

	if(ch==EOF) end=true;

	transform(s.begin(), s.end(), s.begin(), (int (*)(int))tolower);  
	return s;
}
void printdict(){
	map <string, int>::iterator dit;
	 for ( dit = dict.begin( ); dit != dict.end( ); dit++ ){
	 	cout<<dit->first<<"="<<dit->second<<endl;
	 	listt.push(dit->first);
	 }
}
int main(int argc, char const *argv[])
{
	#ifndef LOCAL
	fp=fopen("case1.in","r");
	#else
	printf("used LOCAL");
	#endif
	string word;

	listt.count=0;
	listt.mincount=0;
	while(!end){
		word=getword();
		if(!dict.count(word)) dict[word]=1;
		else{
			dict[word]++;
		}

		cout<<word<<endl;
	}
	printdict();

	listt.print();
	return 0;
}


