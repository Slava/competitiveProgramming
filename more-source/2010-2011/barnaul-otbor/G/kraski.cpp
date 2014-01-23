#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
using namespace std;
ifstream fin("gog.in");
ofstream fout("gog.out");
int n,i,j,x=0,y=0,u,u1;
string q,w;
int main()
{
    fin>>q>>w;
    if(q=="purple")
    {
        for(i=1;i<=w.length();i++)
        {
            if(w[i-1]=='R'&&x<1)
            {
                x=i;
            }
            if(w[i-1]=='B'&&y<1)
            {
                y=i;
            }
        }
    }
    if(q=="green")
    {
        for(i=1;i<=w.length();i++)
        {
            if(w[i-1]=='Y'&&x<1)
            {
                x=i;
            }
            if(w[i-1]=='B'&&y<1)
            {
                y=i;
            }
        }
    }
    if(q=="orange")
    {
        for(i=1;i<=w.length();i++)
        {
            if(w[i-1]=='R'&&x<1)
            {
                x=i;
            }
            if(w[i-1]=='Y'&&y<1)
            {
                y=i;
            }
        }
    }
    if(x>y)
    swap(x,y);
    fout<<x<<" "<<y;
}
