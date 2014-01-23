#include <iostream>

using namespace std;


int main()
{
    char s[300],c[300],*S,*C;
    int i,j=0,ans=1;
    bool a[300][300];
    cin>>s;
    cin>>c;
    for(i=0;i<strlen(s);i++)
        if(s[i]=='*'||s[i]=='?'){ans=0;break;}
    S = s;
    C = c;
    if(!ans)swap(S,C);

    a[0][0]=a[0][1]=a[1][0] = 1;

    for(i=1;i<=strlen(S);i++)
    {
        for(j=1;j<=strlen(C);j++)
        {
            if(C[j-1] == '*')
                a[i][j] = (a[i][j-1] || a[i-1][j]);
            if(S[i-1] == C[j-1] || C[j-1] == '?')
                a[i][j] = a[i-1][j-1];
        }
    }
    if(a[strlen(S)][strlen(C)])cout << "YES";
    else cout << "NO";
}
