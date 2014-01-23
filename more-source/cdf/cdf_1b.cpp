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
