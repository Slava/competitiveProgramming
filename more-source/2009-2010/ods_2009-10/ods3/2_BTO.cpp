#include <iostream>

using namespace std;

int main () {
	freopen ("triangle.in", "r", stdin);
	freopen ("triangle.out", "w", stdout);

	long long n,m,r,sum=0,j=1,z=1;
	cin>>n>>m>>r;
	if(n>m)swap(m,n);
	double k=(double)m/n,i=k;
	int zz=m/n;if(!zz)zz=1;
	while(i<=m)
	{

		if(i>=z){sum+=(n-j)*zz;z++;}
		j++;i=(m*j/n);
	}
	cout<<r-sum;

return 0;
}
