// source :- https://codeforces.com/blog/entry/63903

template <int MOD=1000000007>
struct Modular {
  int value;
  static const int MOD_value = MOD;

  Modular(long long v = 0) { value = v % MOD; if (value < 0) value += MOD;}
  Modular(long long a, long long b) : value(0){ *this += a; *this /= b;}

  Modular& operator+=(Modular const& b) {value += b.value; if (value >= MOD) value -= MOD; return *this;}
  Modular& operator-=(Modular const& b) {value -= b.value; if (value < 0) value += MOD;return *this;}
  Modular& operator*=(Modular const& b) {value = (long long)value * b.value % MOD;return *this;}

  friend Modular power(Modular a, long long e) {
    Modular res = 1; while (e) { if (e&1) res *= a; a *= a; e >>= 1; }
    return res;
  }
  friend Modular inverse(Modular a) { return power(a, MOD - 2); }

  Modular& operator/=(Modular const& b) { return *this *= inverse(b); }
  friend Modular operator+(Modular a, Modular const b) { return a += b; }
  friend Modular operator-(Modular a, Modular const b) { return a -= b; }
  friend Modular operator-(Modular const a) { return 0 - a; }
  friend Modular operator*(Modular a, Modular const b) { return a *= b; }
  friend Modular operator/(Modular a, Modular const b) { return a /= b; }
  friend std::ostream& operator<<(std::ostream& ostr, Modular const& a) {return ostr << a.value;}
  friend bool operator==(Modular const& a, Modular const& b) {return a.value == b.value;}
  friend bool operator!=(Modular const& a, Modular const& b) {return a.value != b.value;}
};

template<int MOD>
struct Matrix {
    int n, m;
    vector<vector<Modular<MOD>>> mat;
 
    Matrix(int _n, int _m) : n(_n), m(_m), mat(n, vector<Modular<MOD>>(m, Modular<MOD>(0))) {}
 
    Matrix operator += (const Matrix &other) {
        for(int i=0; i<n; i++) for(int j=0;j<m;j++)
            mat[i][j] += other.mat[i][j];
        return *this;
    }
 
    Matrix operator -= (const Matrix &other) {
        for(int i=0; i<n; i++) for(int j=0;j<m;j++)
            mat[i][j] -= other.mat[i][j];
        return *this;
    }
 
    Matrix operator * (const Matrix &other) const {
        Matrix res(n, other.m);
        for(int i=0; i<n; i++) for(int k=0;k<m;k++) for(int j=0; j<other.m; j++)
            res.mat[i][j] += mat[i][k] * other.mat[k][j];
        return res;
    }
 
    friend Matrix operator + (Matrix a, const Matrix &b) {
        return a += b;
    }
 
    friend Matrix operator - (Matrix a, const Matrix &b) {
        return a -= b;
    }
 
    Matrix operator *= (const Matrix &other) {
        return *this = *this * other;
    }
 
    vector<Modular<MOD>>& operator [] (int i) {
        return mat[i];
    }
 
    friend Matrix power(Matrix m, long long b) {
        Matrix ret(m.n, m.m);
        for (int i=0; i<m.n; i++)
            ret[i][i] = 1;
        while (b > 0) {
            if (b & 1) ret *= m;
            m *= m;
            b >>= 1;
        }
        return ret;
    }
};