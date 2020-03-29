inline ll mul(ll a,ll b) {
    return (1ll*(a)%mod*(b)%mod)%mod;
}

inline ll add(ll a,ll b) {
    return ((a)%mod+(b)%mod)%mod;
}

inline ll sub(ll a,ll b) {
    return ((a)%mod - (b)%mod + mod)%mod;
}

ll power(ll a,ll b) {
    ll res = 1;
    while(b) {
        if(b&1) res=(res*a)%mod;
        b>>=1;
        a=(a*a)%mod;
    }
    return res;
}

inline ll divide(ll a,ll b) {
    return mul(a%mod,power(b%mod,mod-2));
}