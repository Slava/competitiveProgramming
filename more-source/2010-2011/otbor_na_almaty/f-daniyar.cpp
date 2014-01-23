#include <iostream>
#include <cstdio>
using namespace std;
double t1,v1,t2,v2,s,x1,x2,y,s1,s2,k1,k2,l,c1,c2,time1,time2;
main()
{
    freopen("race.in","r",stdin);
    freopen("race.out","w",stdout);
    cin>>t1>>v1>>t2>>v2>>s;
    c1=1;
    c2=1;
    x1=0;
    x2=0;
    time1=t1;
    time2=t2;
    while(1)
    {
        if(c1==1)
        {
           x1=x1+v1;
           time1--;
           if(time1==0)
           c1=0;
        }
        else if(c1==0)
        {
            time1++;
            if(time1==t1)
            c1=1;
        }
         if(c2==1)
        {
           x2=x2+v2;
           time2--;
           if(time2==0)
           c2=0;
        }
        else if(c2==0)
        {
            time2++;
            if(time2==t2)
            c2=1;
        }
        if(x1>=s&&x2>=s)
        {
            if(x1>x2)
            {
                cout<<"First";
            }
            if(x1<x2)
            {
                cout<<"Second";
            }
            if(x1==x2)
            {
                cout<<"Draw";
            }
            break;
        }
        if(x1>=s&&x2<s)
        {
            cout<<"First";
            break;
        }
        if(x1<s&&x2>=s)
        {
            cout<<"Second";
            break;
        }
    }
    return 0;
}
