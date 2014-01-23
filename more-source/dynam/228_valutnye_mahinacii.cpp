//228
#include <iostream>
using namespace std;

int main (){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
	int n;
	double sum=100,prevdollar,preveuro,dollar,euro,k;
	cin>>n;
	
	cin>>prevdollar>>preveuro;
	for(int i=1;i<n;i++)
	{
		cin>>dollar>>euro;
		k=max(dollar/prevdollar,euro/preveuro);
		if(k>1)sum*=k;
		swap(prevdollar,dollar);swap(preveuro,euro);
	}
	cout.precision(2);
	cout<<fixed<<sum;
	
	return 0;
}
