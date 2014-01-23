#include <iostream>

using namespace std;

bool scmp(char *s1,char *s2,int n)
{
    bool t=true;
    for(int i=1;i<n;i++)
    {
        if(s1[i]!=s2[i])
        {
            t=false;
            break;
        }
    }
    return t;
}

int main ()
{
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
    int N,K;
    char s[1000000];
    cin>>N>>K;
    cin>>s;
    bool t=false;

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(i==j)
            {
                continue;
            }
            else if(s[i]==s[j])
            {
                if(scmp(s+i,s+j,K)==true)
                {
                    t=true;
                    goto end;
                }
            }
        }
    }

    end:
    if(t)
    {
        cout<<"YES";
    }
    else
    {
        cout<<"NO";
    }

    return 0;
}
