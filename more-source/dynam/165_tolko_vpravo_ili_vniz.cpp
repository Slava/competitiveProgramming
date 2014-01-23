//165
#include <iostream>
using namespace std;

int main (){
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);

	int n,m;
	long long z[100][100],a[100][100]={0};
	cin>>n>>m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			{cin>>z[i][j];a[i][j]=0;}
	a[0][0]=1;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++){
			if(i==n-1&&j==m-1)continue;
			a[i+(z[i][j])][j]+=a[i][j];
			a[i][j+(z[i][j])]+=a[i][j];
			}

	cout<<a[n-1][m-1];

	return 0;
}
