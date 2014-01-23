#include <iostream>
#include <algorithm>
using namespace std;
int main (){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int a[1000],b[1000],n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    a[n+1]=0;
    sort(a,a+n+1);
    b[0]=0;b[1]=9999;
    for(int i=2;i<=n;i++)
    {b[i]=(a[i]-a[i-1])+min(b[i-1],b[i-2]);}
    cout<<b[n];
    return 0;}
