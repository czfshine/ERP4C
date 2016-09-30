#include <iostream>

using namespace std;

int main()
{
    __int64 a,b,c;
    cin>>a>>b>>c;
        cout<<(a%c?a/c+1:a/c)*(b%c?b/c+1:b/c);
    return 0;
}