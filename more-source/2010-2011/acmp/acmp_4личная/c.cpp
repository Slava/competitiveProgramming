#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

//#define debug

char a[260], var[30][10];
int n, k, varp[30], v[30], j;

bool NOT (int i);
bool AND (int i);
bool OR (int i);
bool expr(int i);

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    scanf("%s", a);
    #ifdef debug
    printf("Expression have been entered\n\n");
    #endif
    scanf ("%d%d", &n, &k);
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < k; i++)
        {
            scanf("%s", var[i]);
            varp[var[i][0] - 'A'] = i;
            v[i] = (var[i][2] == 'T');
        }
        #ifdef debug
        for (int i = 0; i < k; i++)
            printf("%d=%d\n", i, v[i]);
        #endif
        bool ANS = expr(0);
        if(ANS)printf("TRUE\n");
        else printf("FALSE\n");
    }

    return 0;
}

bool expr(int i)
{
    j = i;
    for (; j < strlen(a); j++)
    {
        if (j > 0 && a[j-1] == 'O' && a[j] == 'R')
            return OR (j+2);
        if (j > 1 && a[j-2] == 'A' && a[j-1] == 'N' && a[j] == 'D')
            return AND (j+2);
        if (j > 1 && a[j-2] == 'N' && a[j-1] == 'O' && a[j] == 'T')
            return NOT (j+2);

    }
    #ifdef debug
        printf("Oops! Error in expr!j=%d\n",j);
    #endif
    return 1;
}

bool NOT (int i)
{
    j = i;
    #ifdef debug
        printf("Yes, Not is in action j=%d\n",j);
    #endif

    if ((a[j] >= 'A' && a[j] <= 'Z') && (a[j+1] == ')'))
    {
        #ifdef debug
        puts("for one var!\n");
        #endif
        j++;
        return !v[varp[a[j-1]]];
    }
    return !(expr(j));
}

bool AND (int i)
{
    #ifdef debug
        printf("Yes, And is in action j=%d\n",j);
    #endif
    j = i;
    bool T = 1;
    for (int k = 0; k < 2; k++){
        for (int z = 0; z < 3; z++){
            while (a[j] == ')')j++;
            while (a[j] == ',')j++;
            while (a[j] >= 'A' && a[j] <= 'Z' && a[j+1] >= 'A' && a[j+1] <= 'Z')j++;
        }
        if (j > 0 && a[j-1] == 'O' && a[j] == 'R')
            T &= OR (j+2);  else
        if (j > 1 && a[j-2] == 'A' && a[j-1] == 'N' && a[j] == 'D')
            T &= AND (j+2); else
        if (j > 1 && a[j-2] == 'N' && a[j-1] == 'O' && a[j] == 'T')
            T &= NOT (j+2);
        else
        {
            T &= v[varp[a[j]]];
        }

    }
    return T;
}

bool OR (int i)
{
    #ifdef debug
        printf("Yes, OR is in action j=%d\n", j);
    #endif
    j = i;
    bool T = 0;
    for (int k = 0; k < 2; k++){
        for (int z = 0; z < 3; z++){
            while (a[j] == ')')j++;
            while (a[j] == ',')j++;
            while (a[j] >= 'A' && a[j] <= 'Z' && a[j+1] >= 'A' && a[j+1] <= 'Z')j++;
        }
        if (j > 0 && a[j-1] == 'O' && a[j] == 'R')
            T |= OR (j+2);  else
        if (j > 1 && a[j-2] == 'A' && a[j-1] == 'N' && a[j] == 'D')
            T |= AND (j+2); else
        if (j > 1 && a[j-2] == 'N' && a[j-1] == 'O' && a[j] == 'T')
            T |= NOT (j+2);
        else
        {
            T |= v[varp[a[j]]];
        }

    }

    return T;

}

