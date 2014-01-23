#include <iostream>

using namespace std;

int n,m;
char a[40][40],ch;	

bool yeah(int x,int y,int &x2, int &y2){
	if((a[x][y+1]!=ch&&a[x][y+1]!=1)||(a[x][y+2]!=ch&&a[x][y+2]!=1)||(a[x+1][y]!=ch&&a[x+1][y]!=1)||(a[x+2][y]!=ch&&a[x+2][y]!=1))return 0;
	
	for(int i=y+3;i<m;i++)
	{
		if(a[x][i]!=ch&&a[x][i]!=1)y2=i-1;break;
		if(i==n-1)y2=m-1;break;
	}
	
	for(int i=x+3;i<n;i++)
	{
		if(a[i][y2]!=ch||a[i][y2]!=1)x2=i-1;break;
		if(i==n-1)x2=n-1;break;
	}
	
	for(int i=x;i<=x2;i++)
	{
		if(a[i][y]!=ch&&a[i][y]!=1)return 0;
	}
	
	for(int i=y;i<=y2;i++)
	{
		if(a[x2][i]!=ch&&a[x2][i]!=1)return 0;
	}
	return 1;
}

void alfa(int x,int y,int x2,int y2)
{
	for(int i=y;i<=y2;i++)
	{
		a[x][i]=1;
	}
	
	for(int i=x;i<=x2;i++)
	{
		a[i][y2]=1;
	}
	
	for(int i=x;i<=x2;i++)
	{
		a[i][y]=1;
	}
	for(int i=y;i<=y2;i++)
	{
		a[x2][i]=1;
	}
}

int main () {
	freopen ("frames.in", "r", stdin);
	freopen ("frames.out", "w", stdout);
	
	cin>>n>>m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++){
			cin>>a[i][j];
			
		}for(int z=0;z<10;z++)
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++){
			if(a[i][j]!='.'){
				int te1,te2;
				ch=a[i][j];//cout<<i<<" "<<j<<endl;
				if(yeah(i,j,te1,te2)){
					cout<<ch;
					alfa(i,j,te1,te2);
				}
			}
		}
	
	
	
	//system("pause");
return 0;
}
