#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int m,n,a[99999],p,o=1,sum;
string s;


int main(){

freopen("A.in","r",stdin);
freopen("A.out","w",stdout);

cin>>n>>m;

cin>>s;

p=s.length();

for(int i=0;i<p;i++){
    if(s[i]>='0' && s[i]<='9') a[p-1-i]=s[i]-48;
    else if(s[i]>='A' && s[i]<='Z') a[p-1-i]=s[i]-55;
    }

sum=a[0]%m;


for(int i=1;i<p;i++){

    o=(o*n)%m;

    sum=sum+(o*a[i])%m;
    }

cout<<sum%m;


return 0;
}
