#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("A.in");
ofstream fout("A.out");
int a[100009],x[100009],y[100009],z[100009],n,i,j;
int main()
{
    fin>>n;
    for (i=1;i<=n;i++) {
        fin>>x[i]>>y[i];
        a[i]=99999;
    }
    for (i=1;i<n;i++)
        for (j=i+1;j<=n;j++) {
            if (a[i]>abs(x[i]-x[j])+abs(y[i]-y[j])) {
                z[i]=j;
                a[i]=abs(x[i]-x[j])+abs(y[i]-y[j]);
            }
            if (a[j]>abs(x[i]-x[j])+abs(y[i]-y[j])) {
                z[j]=i;
                a[j]=abs(x[i]-x[j])+abs(y[i]-y[j]);
            }
        }
    for (i=1;i<=n;i++)
        fout<<z[i]<<" ";
}

