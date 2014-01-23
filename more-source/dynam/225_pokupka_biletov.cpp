#include <iostream>
using namespace std;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int n,a[5002][3],b[5005]={0};
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i][0]>>a[i][1]>>a[i][2];
    b[1]=a[1][0];b[2]=min(b[1]+a[2][0],a[1][1]);
    for(int i=3;i<=n;i++)b[i]=min(min(a[i][0]+b[i-1],a[i-1][1]+b[i-2]),a[i-2][2]+b[i-3]);

    cout<<b[n];

    return 0;
}