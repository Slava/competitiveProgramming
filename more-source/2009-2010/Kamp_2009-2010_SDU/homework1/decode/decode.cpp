#include <fstream>

using namespace std;

ifstream cin("decode.in");
ofstream cout("decode.out");

void read(int a[],int &n)
{
    char s[10009];
    int t,i;
    cin>>s;
    for(i=0;i<strlen(s);i++)
    {
        if(s[i]<='A'&&s[i]>='F')t=(s[i]-55)*16;
        else t=16*(s[i]-48);
        i++;
        if(s[i]>='A'&&s[i]<='F')t+=s[i]-55;
        else t+=s[i]-48;
        a[i/2]=t;
    }n=i/2;

}
int main()
{
    int i,a[10009],b[10009],k[10009],t=32,nb;
    read(a,nb);
    read(b,nb);
    for(i=0;i<nb;i++)
    {
        k[i]=b[i]^t;
        t=a[i]^k[i];
    }
    for(i=0;i<nb;i++)
    {
        t=k[i]/16;
        if(t>9)cout<<(char)(t+55);
        else cout<<t;
        t=k[i]%16;
        if(t>9)cout<<(char)(t+55);
        else cout<<t;
    }

    return 0;
}

