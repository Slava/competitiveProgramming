#include<iostream>
#include<fstream>
using namespace std;
int main()
{
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
int i,mn=40000,sm=0,n,a[105];
cin>>n;
for(i=1;i<=n;i++)
{
cin>>a[i];
sm+=a[i];
mn=min(mn,a[i]);
}
cout<<sm-mn;
return 0;
}