#include <cstdio>
#include <algorithm>
#include <string>
#include <map>
#include <cstdlib>
using namespace std;

map <string ,int> Dict;
FILE *fp;
//debug
fp=stdio;
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
	/* code */
	return 0;
}
