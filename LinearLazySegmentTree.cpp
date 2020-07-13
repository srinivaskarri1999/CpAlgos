// reference :- https://codeforces.com/blog/entry/18051
// fast and efficient segment tree implementation
struct tt {
    int mi;
    tt(int x=INT_MAX) {
        mi=x;
    }
};
// add all elements to base vector, base vector will be used for building segtree.
vector<tt> base;
struct segtree {
    int n;
    vector<tt> st;
    segtree(int x) {
        n = x; st.resize(2*n);
    }
    tt merge(tt const &left, tt const &right) {
        tt res;
        // modify merging operation here
        res.mi = min(left.mi, right.mi);
        return res;
    }
    void build() {
        ifr(i, 0, n) st[i+n] = base[i];
        ifr(i, n, 1) st[i] = merge(st[i<<1], st[i<<1|1]);
    }
    // point update
    void update(int i, ll val) {
        //modity basevalue acc to struct tt
        base[i] = tt(val);
        for(st[i+=n]=base[i]; i>>=1; ) st[i] = merge(st[i<<1], st[i<<1|1]);
    }
    // range query is done on (l, r) inclusive 
    tt query(int l, int r) {
        tt resl, resr; // created with default values set by constructor in struct tt
        for(l+=n, r+=n+1; l<r; l>>=1, r>>=1) {
            if(l&1) resl = merge(resl, st[l++]);
            if(r&1) resr = merge(st[--r], resr);
        }
        return merge(resl, resr);
    }
};