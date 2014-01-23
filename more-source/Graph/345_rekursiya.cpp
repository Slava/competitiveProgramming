#include <iostream>
#include <string>
using namespace std;

string s[101],d[101][101];
int n,i,j,m[101],k;
bool a[101][101]={0},u[101],rek[101]={0};

void dfs(int x)
{
    u[x]=1;
    for(int i=0;i<n;i++)
        if(a[x][i]){
            if(!u[i])dfs(i);
            else if(k==i){rek[k]=1;return;}
        }
}

main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>s[i];
        cin>>m[i];
        for(j=0;j<m[i];j++)
            cin>>d[i][j];
        cin>>s[100];
    }
    for(i=0;i<n;i++)
        for(j=0;j<m[i];j++)
            for(k=0;k<n;k++)
                if(s[k]==d[i][j]){a[i][k]=1;k=n;}

    for(k=0;k<n;k++)
    {
        for(j=0;j<n;j++)u[j]=0;
        dfs(k);
    }



    for(i=0;i<n;i++)
        (rek[i])?cout<<"YES"<<endl:cout<<"NO"<<endl;


}
