#include <iostream>
using namespace std;

int main ()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    long long h,w,s=0,f=0,i=1;

    for(cin>>h>>w;i<=h;i++)s+=i;
    for(i=0;i<=w;i++)f+=i;

    cout<<s*f;

}
