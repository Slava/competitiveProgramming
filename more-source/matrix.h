#ifndef matrix_h
#define matrix_h

#include <cstdio>
#include <cstring>
#include <cassert>

#ifndef modP
#define modP 0
#endif

template <class T>
struct vector {
	T *a, n;
	vector()	{	n = 0;	}
	void resize(int _)	{
		n = _;
		a = new T[n];
		for (int i = 0; i < n; i++)
			a[i] = 0;
	}
	T &operator [] (int i)	{
		assert (i >= 0 && i < n);
		return a[i];	
	}
};

template <class T>
struct matrix {
	vector<T> *a;
	int n;
	matrix() {}
	matrix(int _)	{	this->resize(_);	}
	void resize (int _)	{
		n = _;
		a = new vector<T>[n];
		for (int i = 0; i < n; i++)
			a[i].resize(n);
	}
	vector<T> &operator [] (int i)	{
		assert (i >= 0 && i < n);
		return a[i];
	}
	matrix<T> &operator *= (matrix<T> &b){
		matrix<T> c(n);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				for (int k = 0; k < n; k++)
					if (!modP)
						c[i][j] += a[i][k] * b[k][j];
					else c[i][j] = ((c[i][j] + (a[i][k] * b[k][j]) % modP) % modP + modP) % modP;
		*this = c;
		return *this;
	}
};

template <class T>
matrix<T> pow (matrix<T> a, int n)	{
	matrix<T> res = a;
	for (--n; n; n >>= 1)	{
		if (n & 1)
			res *= a;
		a *= a;
	}
	return res;
}

#endif

