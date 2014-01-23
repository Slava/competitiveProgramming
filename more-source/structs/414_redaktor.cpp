#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

const int N = 1001000;
int n = 2,a[N],pre[N],next[N],i,c = 1,m = 0,len;
char s[N];
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    gets(s); len = strlen(s);
    for(i=0;i<len;i++)
    {

        if(s[i] == '\\'){
			next[n]=next[c];
			pre[n] = c;
			pre[next[c]] = n;
            next[c]=n;
            c=n++;
        }
        else if(s[i]=='<'){
            if(a[c]>0)a[c]--;
            else if(pre[c])
            {
                next[pre[c]]=next[c];
                pre[next[c]]=pre[c];
                c=pre[c];
            }
        }
        else if(s[i]== '^') {
			if (pre[c]) c=pre[c];
		}
        else if(s[i]=='|') {
			if (next[c])
				c=next[c];
		}
        else  a[c]++;

        m=max(m,a[c]);
    }
    cout<<m;
}
