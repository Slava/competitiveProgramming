#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;

int a, b;
char s[2][20] = {"Ciel", "Hanako"};
int main (){
	scanf("%d%d", &a, &b);
	for (int i = 0; ; i++){
		if (i & 1){
			if (b > 21)b-=22;
			else if (a > 0 && b > 11)
				a--, b-= 12;
			else if (a > 1 && b > 1)
				a-=2,b-=2;
			else{
				puts("Ciel");
				return 0;
			}
		}
		else{
			if (a > 1 && b > 1){
				a-=2;b-=2;
			}else if (a > 0 && b > 11){
				a-=1;b-=12;
			}
			else if (b > 21){
				b -= 22;
			}
			else{
				puts("Hanako");
				return 0;
			}
		}
	}
	return 0;
}





// lang: GNU C++
// memory: 1400 KB
// author: imslavko
// submit_date: Apr 30, 2011 7:05:50 PM
// contest: 79
// link: /contest/79/submission/415498
// time: 30 ms
// verdict: Accepted
// problem: 79A - Bus Game
// ID: 415498
// downloaded by very stupid script
