#include <time.h>
#include <iostream>
#include <string.h>
#include <cstdlib>

using namespace std;

int main () {
	srand(time(0));
    int r1 = 0 + rand() % 2;
    int r2 = 0 + rand() % 2;
    int r3 = 0 + rand() % 2;
    int r4 = 0 + rand() % 2;
    int r5 = 0 + rand() % 2;
    char *first[3]={"My father said that I'm fool,","On exam my brother took full,","I've never thought about NULL,"};
    char *second[3]={"And I've found thing called hole,","Suddenly Earth become whole,","My mom is very very tall,"};
    char *third[3]={"My star is RikiMartin,too!","On math exam I took two,","In next morning I'd love to..."};
    char *fourth[3]={"My sister says Manchester's foo,","I'd like to sing 'Alya bakoo',","It's my style of Kung-FU,"};
    char *fifth[3]={"What happend, guys, is it fall?","There four people I want to call.","I've never heard about Knole."};

    cout<<first[r1]<<endl<<second[r2]<<endl<<third[r3]<<endl<<fourth[r4]<<endl<<fifth[r5];
return 0;
        }
