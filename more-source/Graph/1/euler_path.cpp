// Euler path
// Kim Vyacheslav Karaganda KTL
// 2010
#include <cstdio>
#include <vector>

using namespace std;


int main ()
{
//    freopen ("input.txt", "r", stdin);
//    freopen ("output.txt", "w", stdout);

    int n;
    scanf ("%d", &n);
    vector < vector <int> > g (n, vector<int>(n));  // graph
    vector <int> d (n);                             // degree of vertices

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf ("%d", &g[i][j]);                 // input of graph

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            d[i] += g[i][j] > 0;                    // calculating degrees of vertices

    int first = 0;
    while (!d[first]) first++;                      // find start vertix

    bool bad = false;
    int v1 = -1, v2 = -1;                           // find out if we can build cycle or path

    for (int i = 0; i < n; i++)                     // for every vertix
        if (d[i] & 1)                               // if its degree is odd
            if (v1 == -1)                           // find if it is one of two acceptable
                v1 = i;                             // vertices for making euler path
            else if (v2 == -1)
                v2 = i;                             // if there are more than three odd-degree
            else bad = true;                        // we can make neither euler path nor cycle

    if (bad)
    {
        puts ("impossible");
        return 0;
    }

    if (v1 != -1)                                   // we make temp edge for finding cycle
        ++g[v1][v2], ++g[v2][v1];                   // later we will delete it for path

// algorithm starts here

    vector <int> st;                                // we need stack
    st.push_back(first);
    vector <int> ans;

    while (st.size())
    {
        int v = st.back();                          // v = current vertix
        int i;
        for (i = 0; i < n; i++)
            if (g[v][i])                            // find any edge from it
                break;
        if (i == n)                                 // if it has no edges
        {
            ans.push_back (v);                      // we add it to answer
            st.pop_back();                          // and delete from stack
        }
        else
        {
            --g[v][i];                              // else we delete found edge
            --g[i][v];
            st.push_back (i);                       // and add vertix to stack
        }
    }

// algorithm ends here

    if (v1 != -1)                                   // need to delete temp edge ?
    {
        for (int i = 0; i + 1 < ans.size(); i++)
            if ((ans[i] == v1 && ans[i + 1] == v2)  // find that temp edge in answer vector
             || (ans[i] == v2 && ans[i + 1] == v1))
            {
                vector <int> ans2;
                for (int j = i + 1; j < ans.size(); j++)
                    ans2.push_back (ans[j]);        // copy all after this edges [i+1,N)
                for (int j = 1; j <= i; j++)        // (first and last are same!)
                    ans2.push_back (ans[j]);        // and before, so we made path [1,i]
                ans = ans2;
            }
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (g[i][j])                            // check, if there stayed unused edge
                {bad = true;printf ("%d %d %d\n", i, j, g[i][j]);}
    if (bad)
    {
        puts ("impossible");
        return 0;
    }

    for (int i = 0; i < ans.size(); i++)
        printf ("%d ", ans[i] + 1);                 // output answer vertices [1,n]
//        printf ("%d ", ans[i]);                   // or [0,n)

    return 0;
}

