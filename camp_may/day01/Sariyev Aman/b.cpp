#include<iostream>
#include<fstream>
using namespace std;
int main()
{
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
int n,x,y,z,i,j,a=1,b=1,c=1,aa=-1,bb=-2,cc=-3,xx,yy,zz;
cin>>x>>y>>z>>n;
for(i=1;i<=n;i++)
{
cin>>xx>>yy>>zz;
if(xx*x+yy*y+zz*z>aa)
{
c=b;
b=a;
a=i;
cc=bb;
bb=aa;
aa=xx*x+yy*y+zz*z;
}
else if(xx*x+yy*y+zz*z>bb)
{
c=b;
b=i;
cc=bb;
bb=xx*x+yy*y+zz*z;
}
else if(xx*x+yy*y+zz*z>cc)
{
c=i;
cc=xx*x+yy*y+zz*z;
}
}
cout<<a<<" "<<b<<" "<<c;
return 0;
}