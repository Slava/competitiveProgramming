#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;
int main()
{
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
int n,k,s,a,b,c[1005],r[1005],i,j;
long long mx=0,t;
cin>>n>>k>>a>>b>>s;
for(i=1;i<=n;i++)
{
r[i]=0;
cin>>c[i];
}
c[0]=0;
r[0]=r[n+1]=1;
c[n+1]=s;
for(i=n-k+1;i<=n;i++) r[i]=1;
do{
t=0;
for(i=1;i<=n;i++)
{
if(r[i])
{
s=0;
for(j=i-1;j>=0;j--)
{
if(r[j])
{
if(c[i]-c[j]<=b && a<=c[i]-c[j]) s=1;
j=i-100;
}
}
if(!s)
{
i=n+100;
break;
}
s=0;
for(j=i+1;j<=n+1;j++)
{
if(r[j])
{
if(c[j]-c[i]<=b && a<=c[j]-c[i]) s=1;
j=n+100;
}
}
if(!s) i=n+100;
}
}
if(i>n+2) continue;
for(i=1;i<=n;i++)
{
if(r[i])
{
for(j=1;j<=n;j++)
{
if(r[j]) t+=max(c[i],c[j])-min(c[i],c[j]);
}
}
}
mx=max(mx,t);
}while(next_permutation(r+1,r+n+1));
cout<<mx;
return 0;
}
