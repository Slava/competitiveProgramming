#include <iostream>
using namespace std;

int main (){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
	long long n,a[30001],m;
	cin>>m>>n;
	a[0]=1;
	for(int i=1;i<m;i++)a[i]=1;
	for(int i=m;i<=n;i++)a[i]=a[i-1]+a[i-m];
	
	cout<<a[n];
	
	return 0;
}
