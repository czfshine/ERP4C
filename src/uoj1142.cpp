#include <iostream>
#include <map>
using namespace std;

map <int ,long long> m;
long long F(int x){

    if(x<3) return 0;


    if(x==3) return 1;
    if(m.find(x)!=m.end()) return m[x];
    return m[x]=F(x/2)+F((x+1)/2);

}
int main()
{
    int n;
    while(cin >>n&&n){
        cout << F(n) << endl;
    };

    return 0;
}
