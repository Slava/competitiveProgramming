#include<iostream.h>
#include <time.h>
int main () {
    int N;
    cin>>N;
char *noun1[10]={"Dog","Boy","Girl","Friend","Student","Teacher","Driver","Slava","Damir","Islam"};
char *verb[10]={"makes","does","reads","opens","tells","writes","swithces","learns","studies","puts"};
char *noun2[10]={"homework","mistake","door","window","story","news","book","word","notebook","paper"};
for (int i=0;i<N;i++){
    srand ((unsigned) time (NULL));
int q=rand () % 10+0;
cout<<noun1[q]<<"        ";
system("pause");
int w=rand () % 10+0;
cout<<verb[w]<<"        ";
system("pause");
int e=rand () % 10+0;
cout<<noun2[e]<<"        ";
system("pause");
}
return 0;
}
