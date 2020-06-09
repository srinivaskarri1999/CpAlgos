vector<vector<int>> tri(1,vector<int>(2, -1));
int nxt=1;

void insert(ll n) {
    int st = 0, bit;
    ifr(i, 40, 0) {
        bit = (n>>i)&1;
        if(tri[st][bit]==-1) {
            tri.pb( vector<int>(2, -1) );
            st = tri[st][bit] = nxt++;
        } else st = tri[st][bit];
    }
}

ll query(ll n) {
    int st = 0, bit;
    ll res = 0;
    ifr(i, 40, 0) {
        bit = (n>>i)&1;
        if(tri[st][!bit]==-1) st = tri[st][bit];
        else {
            res+=(1ll<<i);
            st = tri[st][!bit];
        }
    }
    return res;
}