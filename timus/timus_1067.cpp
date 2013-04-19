#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std; 

int n;
string s;
vector<string>v;

struct node {
	int st, fn, i;
	vector<node *>link;
	string name() {
		return v[i].substr(st, fn - st);
	}
	node(int _, int __, int ___) {
		i = _; st = __; fn = ___;
	}
}root(0,0,0);

bool cmp(node *a, node *b) {
	return a->name() < b->name();
}

void dfs(node *v, int tab) {
	if (tab >= 0) {
		cout << string(tab, ' ');
		cout << v->name() << "\n";
	}
	sort(v->link.begin(), v->link.end(), cmp);
	for (int i = 0; i < v->link.size(); i++)
		dfs(v->link[i], tab + 1);
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		v.push_back(s);
	}
	sort (v.begin(), v.end());
	for (vector<string>::iterator str = v.begin(); str != v.end(); str++) {
		node *cur = &root; int j = -1, k, found;
		do{
			for (k = ++j; j < str->size(); j++)
				if (str->at(j) == '\\')
					break;
			string s = str->substr(k, j - k);
			found = -1;
			for (int i = 0; i < cur->link.size(); i++)
				if (cur->link[i]->name() == s) {
					found = i; break;
				}
			if (found == -1) {
				found = cur->link.size();
				cur->link.push_back(new node(str - v.begin(), k, j));
			}
			cur = cur->link[found];
		}while(j != str->size());
	}
	dfs(&root, -1);
	return 0;
}
