//183
#include <iostream>
using namespace std;

int main (){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
	long k,p,a[1000000];
	cin>>k>>p;
	a[2]=1;
	for(int i=3;i<=k;i++)
	{
		if(i%2)a[i]=(a[i-1]%p);
		if(!(i%2))a[i]=(a[i-1]+a[i/2])%p;
	}
	cout<<a[k]%p;
	
	return 0;
}
