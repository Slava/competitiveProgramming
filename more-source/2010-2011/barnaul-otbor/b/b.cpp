#include <iostream>
#include <cstdio>
#include <cstring>
#include <string.h>
#include <string>
#include <vector>

using namespace std;

vector <string> a, b;
int N[1000000];

int main ()
{
    freopen ("bugs.in","r",stdin);
    freopen ("bugs.out","w",stdout);


    char s[200000], *t;

    cin.getline(s,200000);

    t =  strtok (s, " ");

    while (t != NULL)
    {
        a.push_back(t);
        t = strtok (NULL, " ");
    }
    for (int j = 0; j < a.size(); j++)
    {
        for (int i = 0; i < a[j].size();i++)
        {
            if (a[j][i] >= 'A' && a[j][i] <= 'Z')
                a[j][i] = a[j][i] - 'A' + 'a';
            switch (a[j][i])
            {
                case '.':
                case '!':
                case '?':
                case ',':
                case ';':
                case '\n':
                case ' ':
                    a[j][i] = '\0';
                default:
                    break;
            }
        }
    }
    a.push_back("\0");
    while(cin >> s)
    {
        if (strlen(s) == 2 && s[0] == s[1] && s[0] == '*')break;
        for (int i = 0; i < strlen(s);i++)
        {
            if (s[i] >= 'A' && s[i] <= 'Z')
                s[i] = s[i] - 'A' + 'a';
            if (s[i] >= '0' && s[i] <= '9')
                s[i] = '\0';
            switch (s[i])
            {
                case '.':
                case '!':
                case '?':
                case ',':
                case ';':
                case '\n':
                    s[i] = '\0';
                default:
                    break;
            }
        }

        for (int j = 0; j < a.size();j++){
            bool T = 0;
            if (a[j].size() == strlen (s))
            {
                for (int k = 0; k < strlen (s); k++)
                    if (a[j][k] != s[k])
                    {
                        T = 1; break;
                    }
            }
            else T = 1;
            if (!T){goto ENDCYC;}
        }

        for (int j = 0; j < b.size(); j++)
        {
            bool T = 0;
            if (b[j].size() == strlen (s))
            {
                for (int k = 0; k < strlen (s); k++)
                    if (b[j][k] != s[k])
                    {
                        T = 1; break;
                    }
            }
            else T = 1;
            if (!T)
            {
                N[j]++;
                goto ENDCYC;
            }
        }
        b.push_back(s);
        N[b.size()-1] = 1;
        ENDCYC:;

    }
    int m = 0;
    for (int i = 0; i < b.size(); i++)
    {
        if (N[m] < N[i])
            m = i;
    }

    for (int i = 0; i < b[m].size(); i++)
        b[m][i] += -'a' + 'A';
    for (int i = 0; i < b[m].size(); i++)
        cout<<b[m][i];


    return 0;
}
