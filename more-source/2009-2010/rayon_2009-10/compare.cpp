#include <iostream>
#include <string>
using namespace std;

long long power(int i){
    long long ret=1;
    for(int j=1;j<=i;j++){
        ret*=10;
        }
    return ret;}

int main ()
{
    freopen("compare.in","r",stdin);
    freopen("compare.out","w",stdout);

    int A[50],B[50],asize=0,bsize=0;
    bool signa=0,signb=0;
    char a[200],b[200];
    long long sum=0;

    for(int i=0;i<51;i++)A[i]=B[i]=0;
    cin>>a>>b;

    if(a[0]=='-'){signa=1;}
    if(b[0]=='-'){signb=1;}

    if(signa>signb){cout<<a<<" < "<<b;goto end;}
    else if(signb>signa){cout<<a<<" > "<<b;goto end;}

    for(int i=strlen(a)-1;i>=signa;i-=8)
    {
        for(int j=0;j<8;j++)
        {
            if((i-j)<signa)break;
            sum+=(a[i-j]-48)*power(j);
        }
        A[asize]=sum;asize++;
        sum=0;
    }

    for(int i=strlen(b)-1;i>=signb;i-=8)
    {
        for(int j=0;j<8;j++)
        {
            if((i-j)<signb)break;
            sum+=(b[i-j]-48)*power(j);
        }
        B[bsize]=sum;bsize++;
        sum=0;
    }

    if(!signa&&!signb&&asize>bsize){cout<<a<<" > "<<b;goto end;}
    if(!signa&&!signb&&asize<bsize){cout<<a<<" < "<<b;goto end;}
    if(signa&&signb&&asize<bsize){cout<<a<<" > "<<b;goto end;}
    if(signa&&signb&&asize>bsize){cout<<a<<" < "<<b;goto end;}

    for(int i=asize-1;i>=0;i--){
        if(A[i]>B[i]&&!signa){cout<<a<<" > "<<b;goto end;}
        if(A[i]<B[i]&&!signa){cout<<a<<" < "<<b;goto end;}
        if(A[i]<B[i]&&signa){cout<<a<<" > "<<b;goto end;}
        if(A[i]>B[i]&&signa){cout<<a<<" < "<<b;goto end;}
        }
    cout<<a<<" = "<<b;

    end:

    return 0;
}
