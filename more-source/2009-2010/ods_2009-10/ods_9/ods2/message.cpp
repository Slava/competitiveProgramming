#include <iostream>
#include <string>
using namespace std;

main (){
freopen("message.in","r",stdin);
freopen("message.out","w",stdout);
	long n,ii=0;
	bool dir=0;
	char a[100][25]={}, s[500]="";
	cin>>n;
	cin>>s;	
	int size=strlen(s);
	int lines;
	//cout<<size;
	if(n==1){for(int i=0;i<size;i++)cout<<s[i];return 0;}
	if(size==n){for(int i=0;i<size;i++)cout<<s[i];return 0;}
	else{
	
	if(size%n==0)lines=size/n;else lines=(size+n)/n;
	
	for(int i=0;i<lines;i++)
	{
		for(int j=1;j<=n;j++)
		{	
			if(ii>size)s[ii]=0;
			if(dir==0){
				a[i][j-1]=s[ii];ii++;
			}
			if(dir){
				a[i][n-j]=s[ii];ii++;
			}
		}
		if(dir)dir=0;
		else dir++;
	}
	end:
	for(int j=0;j<n;j++)
		for(int i=0;i<lines;i++)
			if(a[i][j])
				cout<<a[i][j];
	
	}

	return 0;
}
