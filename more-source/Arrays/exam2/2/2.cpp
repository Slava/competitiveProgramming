#include <fstream.h>
#include <iostream.h>
int main () {
    ifstream fin ("input.txt");
    ofstream fout ("output.txt");
    int n;
    bool no=0;
    fin>>n;
    int a[n][n];
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            fin>>a[i][j];
            }
        }
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if (a[i][j]!=a[j][i]){
                no=1;
                }
            }
        }
    if (no==0)
    fout<<"YES";
    else
    fout<<"NO";
fin.close();
fout.close();
return 0;
}
