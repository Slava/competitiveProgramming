#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("lines.in");
ofstream fout("lines.out");
int a,b,c,x[1009],y[1009],i,j,k,n,e,g,s;
int main ()
{
    fin>>n;
    for (i=1;i<=n;i++)
        fin>>x[i]>>y[i];
    for (i=1;i<n;i++) {
        for (j=i+1;j<=n;j++) {
            a=y[j]-y[i];
            b=x[i]-x[j];
            c=x[i]*(y[i]-y[j])+y[i]*(x[j]-x[i]);
            for (k=1;k<=n;k++)
                if (k!=i && k!=j)
                    if (a*x[k]+b*y[k]+c==0)
                        s++;
        }
    }
    fout<<s;
}





















