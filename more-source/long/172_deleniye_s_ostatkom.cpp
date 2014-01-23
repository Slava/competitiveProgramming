#include <iostream>

using namespace std;

const int m=20006;
int main ()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    short a[m]={0};
	long long b,s,i,x=0;
	char ch[m];
	cin>>ch;s=strlen(ch);
	for(i=0;i<s;++i)
		a[i]=ch[i]-48;
	cin>>b;
	for(i=0;i<s;i++)
        x=(x*10+a[i])%b;

	cout<<x;

}

