#include <iostream>
using namespace std;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    long i,j,n,m,p[100001]={2},l=1,pp,z=0;
    cin>>n>>m;
    if(n<=1&&m>=1){cout<<"1 ";z=1;}
    if(n<=2&&m>=2){cout<<"2 ";z=1;}
    for(i=3;i<=m;i+=2)
    {
        pp=1;
        for(j=0;j<l;j++)
        {
            if(p[j]*p[j]>i)break;
            if((i/p[j])*p[j]==i){pp=0;break;}}
        if(pp){
            p[l]=i;l++;
            if(i<=m&&i>=n){cout<<i<<' ';z=1;}
            }
    }
    if(!z)cout<<"Absent";
}
