#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	long long  n;
	int f=0;
	long long  s=0,a;
	while(cin >>n){
		s=(n+1)*n/2;
		if(f!=0)cout<<endl;
		cout<<s<<endl;

		f++;
	}
	return 0;
}
