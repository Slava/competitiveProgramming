#include <cstdio>

char l[1024], t[1024], *p;
int T, r, c;

void printcol(int c) {
        if(!c) return;
        printcol((c-1)/26);
        putchar(((c-1) % 26) + 'A');
}

main() {
        for(scanf("%d", &T); T-- && scanf("%s", l);) 
                if(sscanf(l,"R%dC%d", &r, &c) == 2) {
                        printcol(c);
                        printf("%d\n", r);
                } 
				else {
                        sscanf(l, "%[A-Z]%d", t, &r);
                        for(p = t, c = 0; *p; p++) c *= 26, c += *p - 'A' + 1;
                        printf("R%dC%d\n", r, c);
                }
        
}




// lang: GNU C++
// memory: 1300 KB
// author: imslavko
// submit_date: Jan 26, 2011 12:53:13 PM
// contest: 1
// link: /contest/1/submission/265419
// time: 160 ms
// verdict: Accepted
// problem: 1B - Spreadsheet
// ID: 265419
// downloaded by very stupid script
