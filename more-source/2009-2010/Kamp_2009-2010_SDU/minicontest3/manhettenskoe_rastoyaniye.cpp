#include <iostream>
#include <cmath>

using namespace std;

struct dot
{
    int x,y;
};

int dist(dot a,dot b)
{
    return abs(a.x-b.x)+abs(a.y-b.y);
}

int main ()
{
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
    int n,i,j,m;
    dot a[200000];
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i].x>>a[i].y;
    a[200].x=a[200].y=100000;
    for(i=0;i<n;i++)
    {
        m=200;
        for(j=0;j<n;j++)
            if(i!=j&&dist(a[i],a[j])<dist(a[i],a[m]))m=j;
        cout<<m+1<<' ';
    }

    return 0;
}
