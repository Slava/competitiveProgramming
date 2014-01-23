#include <fstream>
#include <iostream>
#include <string>
using namespace std;
ifstream fin("carry.in");
ofstream fout("carry.out");
int t[21],r[21],i,j,la,lb,m,res,pere,k;
string a,b;
main()
{
    fin>>a>>b;
    la=a.length();
    for(i=la-1;i>=0;i--)
    {
        j++;
        t[j]=a[i]-48;
    }
    j=0;
    lb=b.length();
    for(i=lb-1;i>=0;i--)
    {
        j++;
        r[j]=b[i]-48;
    }
    for(i=1;i<=20;i++)
    {
        res=t[i]+r[i]+pere;
        pere=0;
        if(res>9)
        {
            k++;
            pere=res/10;
        }
    }
    if(k==0)
    {
        fout<<"No carry operation.";
    }
    if(k==1)
    {
        fout<<"1 carry operation.";
    }
    if(k>1)
    {
        fout<<k<<" carry operations.";
    }
}
