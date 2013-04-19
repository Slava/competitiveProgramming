#include<iostream>
#include<fstream>
using namespace std;
int main()
{
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
int i,j,n,m,k1,k2,l,r,ll[100005],rr[100005],h,w,t;
long long s=0;
cin>>m>>n>>k1>>k2>>l>>r;
for(i=1;i<=l;i++) cin>>ll[i];
for(i=1;i<=r;i++) cin>>rr[i];
ll[0]=rr[0]=0;
ll[l+1]=n;
rr[r+1]=m;
for(i=1;i<=l+1;i++)
{
for(j=1;j<=r+1;j++)
{
h=ll[i]-ll[i-1];
w=rr[j]-rr[j-1];
t=min(h,w);
t=t/2-1;
if(k1<=t)
{
s+=((h+w)*2-min(k1,t)*8-4+(h+w)*2-min(k2,t)*8-4)/2*(min(k2,t)-min(k1,t)+1);
//cout<<((h+w)*2-min(k1,t)*8-4+(h+w)*2-min(k2,t)*8-4)/2*(min(k2,t)-min(k1,t)+1)<<endl;
//((h+w)*2-min(k1,t)*8-2*(2-(h%2)*(w%2))+(h+w)*2-min(k2,t)*8-2*(2-(h%2)*(w%2)))/2*(min(k2,t)-min(k1,t)+1)<<endl;
}
if(t+1<=min(max(h,w)/2-1,k2) && k1<=t+1 && min(h,w)%2)
{
s+=((h+w)*2-(t+1)*8-2)/2;
//cout<<((h+w)*2-(t+1)*8-2)/2<<endl;
//((h+w)*2-(t+1)*8-2*(2-(h%2)*(w%2)))/2<<endl;
}
}
}
cout<<s;
return 0;
}