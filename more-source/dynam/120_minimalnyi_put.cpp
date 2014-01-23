#include <iostream>
using namespace std;

int main (){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n,m,a[100][100];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
			a[0][j]=999;}a[i][0]=999;
		}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(i==1&&j==1){continue;}
			a[i][j]+=min(a[i-1][j],a[i][j-1]);
		}
	}
cout<<a[n][m];
}