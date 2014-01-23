#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector < int >  a[100010],f[100010],z[100010];
long int u[100010],w,h,l[100010],o=1,c[100010],p[100010],ax,ay[100010];
int func1(int ii, int q);
long int mx,m,n,bx;
pair <int,pair<int,int > > a2[100010];
bool func2(int ii,int l)
{
    int i;
    for(i=0;i<p[ii];i++)
    if(z[ii][i]==l)
        return 1;
    return 0;
}
void con1(int k, int r)
{
    int i,j,q;
    u[k]=1;
    for(i=0;i<l[k];i++)
    {
        q=a[k][i];
        if(u[q]==0)
        {
            c[ax]=k;
            ax++;
            con1(q,k);
            ax--;
        }
        else
        {
            if(q!=r && func1(k,q))
            {
                w=1,h++,o=k;
                f[h].push_back(k),ay[h]++,z[k].push_back(h),p[k]++,z[q].push_back(h),p[q]++;
                for(j=ax-1;c[j]!=q;j--)
                    z[c[j]].push_back(h),p[c[j]]++,f[h].push_back(c[j]),ay[h]++;
                f[h].push_back(q),ay[h]++;
            }
        }
    }
}

long int uh[100010];
void con2(int ii,int x,int y,int s,int ww)
{
    if(s==1)
    {
        a2[bx]=make_pair(ii,make_pair(x,y));
        bx++;
    }
    u[ii]=2;
    int j=p[ii]-1,i; p[ii]--;
    int v,w=ww;
    if(j>=0)
    {
        v=z[ii][j];
        if(uh[v]==0)
        {
            uh[v]=1;
            for(i=0;i<ay[v];i++)
                if(u[f[v][i]]==0)
                    u[f[v][i]]=1;
            for(i=0;i<ay[v];i++)
                if(u[f[v][i]]==1)
                {
                    if(w>0)mx++;
                    w++;
                    con2(f[v][i],mx,y+1,1,0);
                }
        }
        con2(ii,x,y,0,w);
    }
    else
    {
        for(i=0;i<l[ii];i++)
        {
            if(u[a[ii][i]]==0)
            {
                if(w>0)mx++;
                w++;
                con2(a[ii][i],mx,y+1,1,0);
            }
        }
    }
}
int main()
{
   freopen("A.in","r",stdin);
   freopen("A.out","w",stdout);
    int e,i,e2;
    cin>>n>>m;
    for(i=0;i<m;i++)
    {
        cin>>e>>e2;
        a[e].push_back(e2),l[e]++,a[e2].push_back(e),l[e2]++;
    }
    con1(1,0);
    for(i=1;i<=n;i++)
        u[i]=0;
    con2(o,0,0,1,0);
    sort(a2,a2+bx);
    i=0;
    while(i<bx)
    {
        printf("%d %d\n",a2[i].second.first,a2[i].second.second);
        i++;
    }

}
    int func1(int ii, int q){
    int i,j;
    for(i=0;i<p[ii];i++)
    for(j=0;j<p[q];j++)
        if(z[ii][i]==z[q][j])
            return 0;
    return 1;
}
