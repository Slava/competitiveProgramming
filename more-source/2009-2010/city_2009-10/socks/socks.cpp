#include <iostream>
#include<iomanip>
using namespace std;


int main ()
{
	freopen("socks.in","r",stdin);
	freopen("socks.out","w",stdout);

    short a[101]={0},b[101]={0},sizea,carry=0;
    char c[101];
    cin>>c;
    sizea=strlen(c);
    for(int i=0;i<sizea;i++){
        a[sizea-1-i]=c[i]-48;
        }

	for(int i=sizea;i>=0;i--)
	{
	    b[i]=(a[i]+10*carry)/2;
	    carry=a[i]%2;

    }
    if(!b[sizea-1])sizea--;
   carry=1;
    for(int i=0;i<sizea;i++)
	{
	    b[i]+=carry;
	    if(b[i]>9){carry=1;b[i]=b[i]-10;}
	    else {carry=0; break;}
    }
    if(carry){b[sizea]=1;sizea++;}
	for(int i=0;i<sizea;i++)
	{
	    cout<<b[sizea-1-i];

    }

	return 0;
}
