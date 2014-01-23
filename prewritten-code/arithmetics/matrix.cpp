template<int N = 100, typename T = long long>
struct Matrix {
	T m[N][N];

	Matrix(T v) {
		memset(m, 0, sizeof(m));
		for (int i = 0; i < N; ++i) {
			m[i][i] = v;
		}
	}

	const T* operator[](const int r) const {
		return m[r];
	}

	T* operator[](const int r) {
		return m[r];
	}

	Matrix<N, T> operator*(const Matrix<N, T>& other) const {
		Matrix<N, T> ret(0);
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				for (int k = 0; k < N; ++k) {
					ret[i][j] = (ret[i][j] + m[i][k] * other[k][j]) % MOD;
				}
			}
		}
		return ret;
	}

	Matrix t() const {
		Matrix ret;
		for (int i = 0; i < N; ++i) {
			ret[i][i] = m[i][i];
			for (int j = 0; j < i; ++j) {
				ret[i][j] = m[j][i];
				ret[j][i] = m[i][j];
			}
		}
		return ret;
	}
};
