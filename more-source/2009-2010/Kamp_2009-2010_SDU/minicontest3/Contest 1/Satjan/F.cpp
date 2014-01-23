#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;
ifstream fin("F.in");
ofstream fout("F.out");
int n,a,b,i,s,B;
double x[100009],y[100009],q1,w1;
int nd(int q,int w) {
    if (q%w==0) return w;
    return nd(w%q,q);
}
int main ()
{
    fin>>n;
    for (i=1;i<=n;i++)
        fin>>x[i]>>y[i];
    for (i=1;i<n;i++) {
        b=y[i+1]-y[i];
        a=x[i+1]-x[i];
       // B+=nd(a,b);
    }
    for (i=2;i<n;i++)
        s+=x[1]*(y[i]-y[i+1])+x[i]*(y[i+1]+y[1])+x[i+1]*(y[1]+y[i]);
    fout<<s/2;
}
