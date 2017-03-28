#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	int f=0;
	int s=0,a;
	while(cin >>n){
		s=(n+1)*n/2;
		if(f!=0)cout<<endl;
		cout<<s<<endl;

		f++;
	}
	return 0;
}
