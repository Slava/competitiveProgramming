#include <iostream>
using namespace std;

int main ()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int n,m,b[110][110],i,j,t,x[100000],y[100000],l=0;
    cin>>n>>m;

    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
        {
            cin>>t;
            if(t){b[i][j]=0;y[l]=i;x[l]=j;l++;}
            else b[i][j]=10000;
        }
    for(i=0;i<l;i++)
    {
        if(y[i]+1 < n  &&  b[y[i]][x[i]]+1 < b[y[i]+1][x[i]])
            {b[y[i]+1][x[i]]=b[y[i]][x[i]]+1;
            y[l]=y[i]+1;x[l]=x[i];l++;}

        if(x[i]+1 < m  &&  b[y[i]][x[i]]+1 < b[y[i]][x[i]+1])
            {b[y[i]][x[i]+1]=b[y[i]][x[i]]+1;
            y[l]=y[i];x[l]=x[i]+1;l++;}

        if(x[i] > 0  &&  b[y[i]][x[i]]+1 < b[y[i]][x[i]-1])
            {b[y[i]][x[i]-1]=b[y[i]][x[i]]+1;
            y[l]=y[i];x[l]=x[i]-1;l++;}

        if(y[i] > 0  &&  b[y[i]][x[i]]+1 < b[y[i]-1][x[i]])
            {b[y[i]-1][x[i]]=b[y[i]][x[i]]+1;
            y[l]=y[i]-1;x[l]=x[i];l++;}
    }
    for(i=0;i<n;i++){
        for(j=0;j<m;j++)
            cout<<b[i][j]<<' ';
        cout<<endl;
    }

    return 0;
}
