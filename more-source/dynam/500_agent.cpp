#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    pair<short,short>a[10005];
    int n,i,t,t1,b[10005];
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>t>>t1;
        a[i]=make_pair(t,t1*-1);
    }
    sort(a,a+n);
    b[0]=999999;
    b[1]=a[1].second*-1;

    for(i=2;i<n;i++)
        b[i]=min(b[i-1],b[i-2])-a[i].second;
    cout<<b[n-1];

}
