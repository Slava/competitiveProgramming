#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;
int i,j,c,t;
double n;
int main()
{
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
    cin>>n;

    for(i=1;i<pow(2,n);i++)
    {
        t=i;j=1;
        while(t>0)
        {
            if(t%2)
                printf("%d ", j);
            t/=2;
            j++;
        }printf("\n");
    }

    return 0;
}
