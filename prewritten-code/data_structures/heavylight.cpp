// heavy-light decomposition
// imslavko@gmail.com
// january 2012

#pragma comment(linker, "/STACK:32000000000")

#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

#define pb push_back

using namespace std; 

const int BlockSize = 300;
const int inf = 1 << 30;

// structure for searching maximum
// on subarray for O(sqrt(n))

struct sqrtDecomposition {
	vector<int> a, b, mxi;
	int size;
	
	sqrtDecomposition() {}
	sqrtDecomposition(vector<int> r) {
		init(r);
	}

	void init(vector<int> &r) {
		a = r;
		size = (int)a.size();
		b.resize(a.size()/BlockSize + 1, -inf-1);
		mxi.resize(b.size());
		int bli = 0, j = 0;
		for (int i = 0; i < size; i++) {
			if (b[bli] < a[i]) {
				b[bli] = a[i];
				mxi[bli] = i;
			}
			j++;
			if (j == BlockSize) {
				j = 0; bli++;
			}
		}
	}

	int getMaxIndex(int l, int r) {
		if (l > r)swap(l, r);
		int ans = -inf, lb = l / BlockSize, rb = r / BlockSize, id = -1;

		if (lb == rb) {
			for (int i = l; i <= r; i++)
				if (a[i] > ans) {
					ans = a[i];
					id = i;
				}
		} else {
			for (int i = l, end = (lb+1)*BlockSize; i < end; i++)
				if (a[i] > ans) {
					ans = a[i];
					id = i;
				}
			for (int i = lb + 1; i < rb; i++)
				if (ans < b[i]) {
					ans = b[i];
					id = mxi[i];
				}
			for (int i = rb*BlockSize; i <= r; i++)
				if (ans < a[i]) {
					ans = a[i];
					id = i;
				}
		}
		return id;
	}

	int getMax(int l, int r) {
		return a[getMaxIndex(l,r)];
	}

	int getMaxSuffix(int l) {
		return getMax(l,size-1);
	}

	void update(int pos, int newVal) {
		int bl = pos / BlockSize;
		a[pos] = newVal;
		b[bl] = -inf;
		int j = bl * BlockSize;
		for (int i = 0; i < BlockSize && i+j < size; i++)
			if (b[bl] < a[i+j]) {
				b[bl] = a[i+j];
				mxi[bl] = i+j;
			}
	}
};

const int N = 101010;

// all stuff we need for this problem
int n, heaviest[N], sizeSubtree[N], first[N],
	relatesTo[N], used[N], parent[N], numberInPath[N];
vector<sqrtDecomposition> pathMax;
vector<vector<int> > paths;
vector<int> g[N], ls, level;
sqrtDecomposition lcaFind;

int radiation[N];	// relates to problem

// find least common ancestor
int lca(int l, int r) {
	return ls[lcaFind.getMaxIndex(first[l], first[r])];
}

// depth-first-search helps us find
// parent, level, size of subtree and
// heaviest subtree of every node
// and set up the lca
void dfs(int v, int p = -1, int lvl = 0) {
	level.pb(lvl);
	ls.pb(v);
	parent[v] = p;
	sizeSubtree[v] = 1;

	for (int i = 0; i < (int)g[v].size(); i++) {
		int to = g[v][i];
		if (to != p) {			// if we do not go to parent
			dfs(to,v,lvl+1);	// dfs it
			// add its size to out size
			sizeSubtree[v] += sizeSubtree[to];
			ls.pb(v);			// it ourself to list
			level.pb(lvl);
			// check if current subtree is the heaviest
			if (heaviest[v] == -1 
			|| (sizeSubtree[to] > sizeSubtree[heaviest[v]]))
				heaviest[v] = to;
		}
	}
}

void buildPath(int v) {
	int pathNumber = (int)paths.size();
	vector<int> path;
	while (!used[v]) {
		used[v] = 1;
		relatesTo[v] = pathNumber;
		numberInPath[v] = (int)path.size();
		path.pb(v);

		// go higher only if v is heaviest subtree of p
		int to = parent[v];
		if (to == -1 || heaviest[to] != v)
			break;
		v = to;
	}


	// add new path in decomposition
	paths.pb(path);
	pathMax.pb(sqrtDecomposition(vector<int>(path.size())));
}

void updateVertix(int x, int val) {

	// increase in data structure
	// of path which x relates to
	// in place where x is placed
	// yes, it sounds terrible, I know
	
	pathMax[relatesTo[x]].update(numberInPath[x], val);

}

// find max on top-v path, 
// top must be higher than v
int findMaxOnPath(int v, int top) {
	int ret = -inf;
	// easy case, if they are in same path
	if (relatesTo[top] == relatesTo[v])
		return pathMax[relatesTo[v]].getMax(numberInPath[v], numberInPath[top]);
	// else it divides to 3:
	// path from v to end of its path
	// parts of paths between path of v and path of top
	// part of path of top
	// that's easy, I believe
	
	ret = max(ret, 
		pathMax[relatesTo[v]].getMaxSuffix(numberInPath[v]));
	

	v = parent[paths[relatesTo[v]].back()]; // go to parent of this path
	while (v!=-1 && relatesTo[v] != relatesTo[top]) {
		ret = max(ret, pathMax[relatesTo[v]].getMaxSuffix(numberInPath[v]));
		v = parent[paths[relatesTo[v]].back()]; // go to parent of this path
		// remark: we can continue from center of new path
	}


	ret = max(ret,
		pathMax[relatesTo[top]].getMax(numberInPath[v], numberInPath[top]));

	return ret;
}

int findMax(int x, int y) {
	int lca = ::lca(x,y);


	// decompose path x-y
	// to two paths: x-lca, y-lca
	return max(findMaxOnPath(x,lca), findMaxOnPath(y,lca));
}

int main() {
	// initially we don't know heaviest subtree
	// and don't know which pathes are set
	memset(heaviest, -1, sizeof heaviest);
	memset(relatesTo, -1, sizeof relatesTo);

	// input graph
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int x, y; scanf("%d%d", &x, &y);
		x--; y--;
		g[x].pb(y);
		g[y].pb(x);
	}


	dfs(0);
	for (int i = 0; i < (int)level.size(); i++)
		level[i] = -level[i];
	// build first[] array, first occurance in list ls[], need for lca
	for (int i = (int)ls.size() - 1; i >= 0; i--)
		first[ls[i]] = i;
	lcaFind.init(level);


	// now lca is ready
	for (int i = 0; i < n; i++)
		if (heaviest[i] == -1)	// we start from all vertices
			buildPath(i);		// that doesn't have any subtree
	
	// heavy-light decomposition
	

	int m;
	// now input queries
	scanf("%d", &m);

	for (int i = 0; i < m; i++) {
		int x, y;
		char s[2];	// string of query
		scanf("%s%d%d", s, &x, &y);
		if (s[0] == 'I') {
			x--;
			radiation[x] += y;
			updateVertix(x, radiation[x]);
		} else {
			// here the fun starts
			x--; y--;
			printf("%d\n", findMax(x,y));
		}
	}

	return 0;
}

