#include <cstdio>
#include <algorithm>
#include <string>
#include <map>
#include <cstdlib>
using namespace std;

map <string ,int> Dict;
//debug
#ifdef LOCAL
#define fp stdin 
#else
FILE *fp;
#endif
string getword(){
	char ch;
	string s;
	while((ch=getc(fp))!=EOF){
		if(ch=='-'){

			if(getc(fp)=='\n'){
				continue;
			}else{
				fseek(fp,ftell(fp)-1,SEEK_CUR);
				break;
			}
		}

		if(ch>'A'&&ch<'Z' || ch>'a'&&ch<'z')
			s.push_back(ch);
		else
			break;
	}
}
int main(int argc, char const *argv[])
{
	#ifndef LOCAL
	fp=fopen("case1.in","r");
	#else
	printf("used LOCAL");
	#endif
	return 0;
}


