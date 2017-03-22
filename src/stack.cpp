#include <stdio.h>
#include <queue>
#include <vector>
#include <utility>

#include <string>
#include <stack>
#include <iostream>  
#include <stack>

using namespace std;

int main(int argc, char const *argv[])
{stack <string> s1;
	string a("gggg");

	s1.push(a);
	s1.push(a);
	a="1111";
	cout << "mystack.top() is now " << s1.top() << endl;  
	s1.push(a);
	cout << "mystack.top() is now " << s1.top() << endl;
	return 0;
}