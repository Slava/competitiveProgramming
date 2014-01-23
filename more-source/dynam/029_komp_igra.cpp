#include <iostream>
using namespace std;

int main (){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
	long n,a[30001]={0},b[30001]={0};
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	b[2]=abs(a[2]-a[1]);b[1]=0;
	
	for(int i=3;i<=n;i++)
	{
		b[i]=min(abs(a[i-1]-a[i])+b[i-1],b[i-2]+abs(a[i-2]-a[i])*3);
	}
	cout<<b[n];
	
	return 0;
}
