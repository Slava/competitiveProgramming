#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;

string s,q;
int n,z,k;

int main()
{
freopen("next.in","r",stdin);
freopen("next.out","w",stdout);
    cin>>s;

    n=s.length();

    for(int i=0;i<n;i++)
    {
        if(s[i]=='0')
        {
            z++;
        }
        else break;
    }

    for(int i=n-2;i>0;i--)
    {
        if(s[i]=='0')
        {
            k++;
        }
        if(s[i]=='1' && s[i-1]=='0')
        {
            if(i<=z)z--;
            if(k+1<z || k+1==z && i<(n+1)/2)
            {
                swap(s[i],s[i-1]);

                cout<<s;
                exit(0);
            }
            k=0;
        }
    }

        for(int i=n-1;i>0;i--)
        {
            if(s[i]=='0')
            {
                s[i]='1';
                cout<<s;
                exit(0);
            }
        }




    return 0;
}

