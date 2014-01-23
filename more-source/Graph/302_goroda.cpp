#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int p[10005] , r[10005] , n,m=0;
pair<double , pair<int,int> > a[1000050];
double x[10005],y[10005],s=-1;

int FindSet(int x)
{
    if (p[x]!=x) p[x]= FindSet(p[x]);
    return p[x];
}

void Union(int a,int b)
{
    a=FindSet(a);
    b=FindSet(b);

    if (r[a] > r[b]) p[b] = a; else
    {
        p[a]=b;
        if (r[a] == r[b]) r[b]++;
    }
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin>>n;

    for(int i=0;i<n;i++)
        cin>>x[i]>>y[i];


    for (int i=1;i<=n;i++) p[i]=i;

    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            {a[m]=make_pair((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]),make_pair(i,j));m++;}


    sort(a,a+m);

    for (int i=0;i<m;i++)
    if (FindSet(a[i].second.second)!=FindSet(a[i].second.first)) {
        Union(a[i].second.second , a[i].second.first);
        s=max(s,a[i].first);
    }

    s=sqrt(s);
    cout.precision(2);
    cout<<fixed<<s;
}
