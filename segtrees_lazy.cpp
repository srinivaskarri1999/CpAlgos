struct tt {
    ll mi;
    tt(ll y=inf) {
        mi=y;
    }
};
tt base[N];
template<typename T,typename T1>
struct segtree {
    T1 n;
    vector<T>    tree;
    vector<T1>  lazy;
    vector<bool> clazy;
    segtree(int x){
        n = x;
        // assign initial values
        tree.resize(4 * n + 5);
        clazy.assign(4 * n + 5, 0);
        lazy.assign(4 * n + 5, 0);
    } 
    //Modify merge according to the question
    void merge(T &cur,T &l,T &r) {
        cur.mi = min(l.mi,r.mi);
    }
    //Modify propagate function for lazy propagation
    void propagate(int l,int r,int pos) {
        if(l!=r) {
            clazy[2 * pos + 1] = 1;
            clazy[2 * pos + 2] = 1;
            lazy[2 * pos + 1] += lazy[pos];
            lazy[2 * pos + 2] += lazy[pos];
        }
        // modify this tree[pos] line acc to question
        tree[pos].mi += lazy[pos];
        clazy[pos] = 0;
        lazy [pos] = 0;
    } 
    void build(int l,int r,int pos) {
        if(l==r) {
            //Modify here acc to question
            tree[pos] = a[l]; return;
        }
        int mid = l + (r - l) / 2;
        build(l ,mid ,2 * pos + 1);
        build(mid+1 ,r ,2 * pos + 2);
        merge(tree[pos] ,tree[2 * pos + 1] ,tree[2 * pos + 2]);
    } 
    T query(int l,int r,int s,int e,int pos) {
        if( clazy[pos] )
            propagate( l, r, pos);
        if(r<s || e<l){
            // modify here acc to T datatype
            T tem; return tem;
        }
        if(s<=l && r<=e)
            return tree[pos];
        int mid = l + ( r - l ) / 2;
        T p1 = query(l, mid, s, e, 2 * pos + 1);
        T p2 = query(mid+1, r, s, e, 2 * pos + 2);
        T p; merge(p, p1, p2);
        return p;
    } 
    T pquery(int l,int r,int ind,int pos)  {
        if(clazy[pos])
            propagate(l, r, pos);
        if(l==r)
            return tree[pos];
        int mid = l + (r-l)/2;
        if(ind<=mid)
            return pquery(l, mid, ind, 2*pos + 1);
        else
            return pquery(mid+1, r, ind, 2*pos+2);
    } 
    void update(int l,int r,int s,int e,T1 val,int pos) {
        if(clazy[pos])
            propagate(l, r, pos);
        if(r<s || e<l)
            return;
        if(s<=l && r<=e) {
            //Modify Lazy operation
            clazy[pos] = 1;
            lazy[pos] += val;
            propagate(l, r, pos);
            return;
        }
        int mid = l + (r-l)/2;
        update(l, mid, s, e, val, 2 * pos + 1);
        update(mid+1, r, s, e, val, 2 * pos + 2);
        merge(tree[pos], tree[2*pos + 1], tree[2*pos+2]);
    }
    void pupdate(int l,int r,int ind,T1 val,int pos) {
        if(clazy[pos])
            propagate(l, r, pos);
        if(l==r) {
            //Modify Lazy operation 
            clazy[pos] = 1;
            lazy [pos] = val;
            propagate(l, r, pos);
            return;
        }
        int mid = l + (r-l)/2;
        if(ind <= mid)
            pupdate(l, mid, ind, val, 2*pos+1);
        else
            pupdate(mid+1, r, ind, val, 2*pos+2);
        merge(tree[pos],tree[2*pos+1],tree[2*pos+2]);
    }
    T query(int l,int r)            { return query(0,n-1,l,r,0); }
    T query(int l)                  { return pquery(0,n-1,l,0); }
    void update(int l,int r,T1 val) { update(0,n-1,l,r,val,0); }
    void update(int l,T1 val)       { pupdate(0,n-1,l,val,0); } 
    void build()                    { build(0,n-1,0); }
};