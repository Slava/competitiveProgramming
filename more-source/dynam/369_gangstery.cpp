#include <iostream>
#include <algorithm>
using namespace std;

int main ()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int i,n,k,t,T[1010],S[1010],P[1010],l=0;
    short A[105]={0},B[105]={0},*a=A,*b=B;
    pair< int,pair<int,int> >p[1010];
    cin>>n>>k>>t;
    for(i=0;i<n;i++)cin>>T[i];
    for(i=0;i<n;i++)cin>>P[i];
    for(i=0;i<n;i++)cin>>S[i];
    for(i=0;i<n;i++)
        if(S[i]<=k&&T[i]<=t&&T[i]>=S[i])
            {p[l]=make_pair(T[i],make_pair(P[i],S[i]));l++;}
    sort(p,p+l);
    //time,money,fat
    a[p[0].second.second]=p[0].second.first;
    for(i=1;i<l;i++)
    {
        for(int j=0;j<=105;j++)
            for(int k=0;k<=(p[i].first-p[i-1].first);k++)
            {
                if(j+k<=105)b[j+k]=max(b[j+k],a[j]);
                if(j-k>=0)b[j-k]=max(b[j-k],a[j]);
            }


        b[p[i].second.second]+=p[i].second.first;
        swap(a,b);
    }
    short maxi=0;
    for(i=1;i<=105;i++)maxi=max(maxi,a[i]);
    cout<<maxi;

    return 0;
}
