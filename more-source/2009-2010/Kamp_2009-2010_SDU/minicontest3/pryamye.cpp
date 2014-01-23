#include <iostream>
using namespace std;

struct dot
{
    int x,y;
};

int main()
{
    freopen("lines.in","r",stdin);
    freopen("lines.out","w",stdout);
    int n,i,j,k,s=0;
    dot a[200000];
    cin>>n;

    for(i=0;i<n;i++)
        cin>>a[i].x>>a[i].y;
    for(i=0;i<n;i++)
        for(j=i+1;j<n;j++)
            if(i!=j)for(k=0;k<n;k++)
            s+=(k!=i&&j!=k)*((a[j].y-a[i].y)*(a[k].x-a[i].x)==(a[k].y-a[i].y)*(a[j].x-a[i].x));
    cout<<s;
}
