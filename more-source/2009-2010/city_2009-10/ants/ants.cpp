#include <iostream>
using namespace std;

int main()
{
    freopen("ants.in","r",stdin);
    freopen("ants.out","w",stdout);

    int n,l,a[100000],b[100000],s=0;

    cin>>n>>l;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++){
        cin>>b[i];
        if(b[i]==1)s=max(l-a[i],s);
        else s=max(a[i],s);
        }
    cout<<s;

    return 0;
}
