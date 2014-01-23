#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <cassert>
#include <set>

using namespace std;

string s[100000], t;
set<string>ans;
char str[30]; int n, sz;
int main (){
	FILE *dict = fopen("/usr/share/dict/words", "r");
	assert(dict);
	for (;fscanf(dict, "%s", str) == 1; n++)
		s[n] = str;
	fclose(dict);
	puts("ready");
	for (;;){
		scanf("%s", str);sort(str, str + strlen(str));
		puts("~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~");
		sz = strlen(str);ans.clear();
		do{
			t = str;
			for (int i = 3; i <= sz; i++)
				if (binary_search(s, s + n, t.substr(0, i)))
					ans.insert(t.substr(0, i));
		}while(next_permutation(str, str + sz));
		for (set<string>::iterator i = ans.begin(); i != ans.end(); i++)
			printf("%s\n", i->c_str());
		puts("~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~");
	}
}

