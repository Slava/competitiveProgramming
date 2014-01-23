#include <iostream>
using namespace std;

int main (){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	char a[300][300];
	short b[300][300]={0},n;
	bool c[300][300]={0},neush;
	cin>>n;

	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			a[i][j]-=48;
			b[i][j]=a[i][j];
			c[i][j]=0;
		}
		b[0][i]=b[i][0]=9999;
	}

	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==1&&j==1)neush=n;
			else{b[i][j]+=min(b[i-1][j],b[i][j-1]);}
		}
	}

	c[n][n]=1;


	for(int i=n,j=n;i>0&&j>0;i-=0){
		if(b[i][j]-a[i][j]==b[i-1][j]){i--;c[i][j]=1;}
		else {j--;c[i][j]=1;}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			(c[i][j])?cout<<'#':cout<<'.';
		}
		cout<<endl;
	}

	return 0;
}
