//122
#include <iostream>
using namespace std;

int main (){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
	long long n,a[30001],b[30001],maxi=1,maxii;
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	b[0]=1;
	for(int i=1;i<n;i++)
	{
		maxii=0;
		for(int j=0;j<i;j++){
			if(a[i]>a[j])maxii=max(maxii,b[j]);
		}
		b[i]=maxii+1;
		maxi=max(maxi,b[i]);
	}
	cout<<maxi;
	
	
	return 0;
}
