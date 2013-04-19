#include <iostream>
using namespace std;
int i,o,n,m,k,nm[50001],n_m[50001],n_n[50001],c;
bool bb[50001];
int main()
{
	cin>>n>>m;
	bb[1]=true;
	for(i=2;i<=n;i++) 
		if (!bb[i])
			for(o=2*i;o<=n;o+=i)bb[o]=true;
	for(i=2;i<=n;i++) 
		if (bb[i])
		{
			k=i;
			for(o=2;o<=i;o++)
				if (!bb[o])
				{
					while(k%o==0)
					{
						nm[o]++;
						k/=o; 
					}
					if (k==1) break; 
				} 
		}
		else
		{
			nm[i]++; 
		}
	for(i=2;i<=m;i++) 
		if (bb[i])
		{
			k=i;
			for(o=2;o<=i;o++)
				if (!bb[o])
				{
					while(k%o==0)
					{
						n_m[o]++;
						k/=o; 
					} 
					if (k==1) break; 
				} 
		}
		else
		{
			n_m[i]++; 
		}
	for(i=2;i<=n-m;i++) 
		if (bb[i])
		{
			k=i;
			for(o=2;o<=i;o++)
				if (!bb[o])
				{
					while(k%o==0)
					{
						n_n[o]++;
						k/=o; 
					} 
					if (k==1) break; 
				} 
		}
		else
		{
			n_n[i]++; 
		}
	for(i=2;i<=n;i++)
	{
		nm[i]-=n_n[i]+n_m[i];
		if (nm[i]>0) c++; 
	}
	cout<<c;
	return 0;
}
