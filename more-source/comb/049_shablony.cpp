#include <iostream>

using namespace std;

char p1[20],p2[20];
int a = 1, i, j, b;
bool u1[20],u2[20];

int main ()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    cin >> p1 >> p2;
    for(i = 0; i < strlen(p1); i++)
    {
        b = 0;
        for(j = 0; j < 10; j++)u1[j] = u2[j] = 0;
        if(p1[i] >= '0' && p1[i] <= '9')
            u1[p1[i] - '0'] = 1;
        else if(p1[i] == '?')for(j = 0; j < 10; j++)u1[j] = 1;
        else for(j = p1[i] - 'a'; j < p1[i] - 'a'+4; j++)
            u1[j] = 1;

        if(p2[i] >= '0' && p2[i] <= '9')
            u2[p2[i] - '0'] = 1;
        else if(p2[i] == '?')for(j = 0; j < 10; j++)u2[j] = 1;
        else for(j = p2[i] - 'a'; j < p2[i] - 'a'+4; j++)
            u2[j] = 1;
        for(j = 0; j < 10; j++)
            if(u1[j] && u2[j])b++;
        a *= b;
    }

    cout << a;

    return 0;
}
