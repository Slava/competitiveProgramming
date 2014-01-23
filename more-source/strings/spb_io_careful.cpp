#include <cstdio>
#include <cstring>

using namespace std;

int main ()
{
    freopen ("careful.in", "r", stdin);
    freopen ("careful.out", "w", stdout);

    char word[1000000], text[1000000], t[1000000];
    int lines, textlen, wordlen, initialwordlen;
    bool overwrite = 0;
    gets (word);
    wordlen = strlen (word);
    initialwordlen = wordlen;
    scanf ("%d", &lines);
    gets (text);
    for (int i = 0; i < lines; i++)
    {
        overwrite = 0;
        gets (t);
        textlen = strlen (text);
        if ( text[textlen - 1] == 45 ) overwrite = 1;
        if (!overwrite) text [textlen] = ' ';
        for (int j = 0; j <= strlen (t); j++)
            text [textlen - overwrite + j + (!overwrite)] = t[j];
    }


    textlen = strlen (text);

    //prepring for prefix func
    for (int i = 0; i <= textlen; i++)
        word[wordlen + i] = text[i];
    word [wordlen] = '$';
    wordlen = strlen (word);

    //to lower case
    for (int i = 0; i < wordlen; i++)
        if (word[i] >= 'A' && word[i] <= 'Z')
            word[i] += -'A' + 'a';

    //prefix func
    int k = -1, d[1000000], answer = 0;
    d[0] = -1;

    for (int i = 1; i < wordlen; i++)
    {
        while (k >= 0 && word[k + 1] != word[i])
            k = d[k];
        if (word[k + 1] == word[i])
            k++;
        d[i] = k;
        if (d[i] == initialwordlen - 1) answer++;
    }

    printf ("%d", answer);

    return 0;
}
