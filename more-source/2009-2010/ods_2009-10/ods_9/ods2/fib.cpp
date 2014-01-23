#include <iostream>
using namespace std;

int n;
long long j,i=1,n1=1,n2=1;
short x1[10000]={0},x2[10000]={0};

void pluss(short a[],short b[],long long &n1,long long n2){
    n1=max(n1,n2);
    short carry=0;
    for(int i=0;i<n1;i++)
    {
        a[i]+=b[i]+carry;
        if(a[i]>9){carry=1;a[i]=a[i]%10;}
        else carry=0;
        }
    if(carry){
        a[n1]=1;
        n1++;

        }
    }

int main (){
	freopen("fib.in","r",stdin);
	freopen("fib.out","w",stdout);
	x1[0]=x2[0]=1;
	bool nnn=0;
	short s=1;
	cin>>n;

	while(i<=n+100)
	{
	    if(!nnn){
        pluss(x1,x2,n1,n2);nnn++;
        if(i==n)goto end;
		for(j=n2-1;j>=0;j--){
            s=x2[j];i++;

            //cout<<s;

            if(i==n)goto end;
            }//cout<<endl;
                }
        else{
        pluss(x2,x1,n2,n1);nnn=0;
        if(i==n)goto end;
		for(j=n1-1;j>=0;j--){
		    s=x1[j];i++;

		    //cout<<s;

		    if(i==n)goto end;
		    }//cout<<endl;
		    }


	}
	end:
	cout<<s;
	cin>>s;
	return 0;
}
