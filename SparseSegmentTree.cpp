// Reference :- https://codeforces.com/blog/entry/63903
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

// -- SPARSE SEGTREE START 

const int NN = 4e7 + 5;
struct node {
    int l, r;
    pair<Modular<mod>, Modular<mod>> val;
} tr[NN];
int tot = 0;

const int N = 5e5 + 5;
int version[N];
SuffixArray<string, N> S;

Modular<mod> pre[N], w[N];
int n;

pair<Modular<mod>, Modular<mod>> query(int nd,int s,int e,int l,int r) { // sum query in segtree
    if(s > r || e < l || !nd) return {0, 0};
    else if(l <= s && e <= r) {
        return tr[nd].val;
    }
    int m = (s + e) >> 1;
    auto p1 = query(tr[nd].l, s, m, l, r);
    auto p2 = query(tr[nd].r, m + 1, e, l, r);
    return {p1.fi + p2.fi, p1.se + p2.se};
}

void merge(int &nd1,int nd2) { // merge two segtrees
    if(!nd1 || !nd2) {
        nd1 |= nd2;
        return;
    }
    tr[nd1].val.fi += tr[nd2].val.fi;
    tr[nd1].val.se += tr[nd2].val.se;
    merge(tr[nd1].l, tr[nd2].l);
    merge(tr[nd1].r, tr[nd2].r);
}

void upd(int &nd,int s,int e,int idx) { // for initializing segtrees
    if(!nd) nd = ++tot;
    tr[nd].val = {1, pre[idx - 1]};
    if(s == e) return;
    int m = (s + e) >> 1;
    if(idx <= m)
        upd(tr[nd].l, s, m, idx);
    else
        upd(tr[nd].r, m + 1, e, idx);
}

// -- SPARSE SEGTREE END